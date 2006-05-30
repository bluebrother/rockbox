#!/bin/sh

# this is where this script will store downloaded files and check for already
# downloaded files
dlwhere="$HOME/tmp"

# will append the target string to the prefix dir mentioned here
# Note that the user running this script must be able to do make install in
# this given prefix directory. Also make sure that this given root dir
# exists.
prefix="/usr/local"

# This directory is used to extract all files and to build everything in. It
# must not exist before this script is invoked (as a security measure).
builddir="$HOME/build-rbdev"

##############################################################################

findtool(){
  file="$1"

  IFS=":"
  for path in $PATH
  do
    # echo "checks for $file in $path" >&2
    if test -f "$path/$file"; then
      echo "$path/$file"
      return
    fi
  done
}

input() {
    read response
    echo $response
}

#$1 file
#$2 URL"root
getfile() {
  tool=`findtool curl`
  if test -z "$tool"; then
    tool=`findtool wget`
    if test -n "$tool"; then
      # wget download
      echo "download $2/$1 using wget"
      $tool -O $dlwhere/$1 $2/$1
    fi
  else
     # curl download
      echo "download $2/$1 using curl"
     $tool -Lo $dlwhere/$1 $2/$1
  fi
  if test -z "$tool"; then 
    echo "couldn't find downloader tool to use!"
    exit
  fi
  

}

###########################################################################
# Verify download directory or create it
if test -d "$dlwhere"; then
  if ! test -w "$dlwhere"; then
    echo "$dlwhere exists, but doesn't seem to be writable for you"
    exit
  fi
else
  mkdir $dlwhere
  if test $? -ne 0; then
    echo "$dlwhere is missing and we failed to create it!"
    exit
  fi
  echo "$dlwhere has been created to store downloads in"
fi

echo "Download directory: $dlwhere (edit script to change dir)"
echo "Install prefix: $prefix/[target] (edit script to change dir)"
echo "Build dir: $builddir (edit script to change dir)"

###########################################################################
# Verify that we can write in the prefix dir, as otherwise we will hardly
# be able to install there!
if test ! -w $prefix; then
  echo "WARNING: this script is set to install in $prefix but has no"
  echo "WARNING: write permission to do so!"
fi


###########################################################################
# If there's already a build dir, we don't overwrite it
if test -d $builddir; then
  echo "you have a $builddir dir already, please remove and rerun"
  exit
fi

cleardir () {
  # $1 is the name of the build dir
  # delete the build dirs and the source dirs
  rm -rf $1/build-gcc $1/build-binu $1/gcc* $1/binutils*
}

buildone () {

gccpatch="" # default is no gcc patch
gccver="4.0.3" # default gcc version
binutils="2.16.1" # The binutils version to use

case $1 in
  [Ss])
    target="sh-elf"
    gccurl="http://www.rockbox.org/twiki/pub/Main/CrossCompiler"
    gccpatch="gcc-4.0.3-rockbox-1.diff"
    ;;
  [Mm])
    target="m68k-elf"
    gccver="3.4.6"
    ;;
  [Aa])
    target="arm-elf"
    ;;
  *)
    echo "unsupported"
    exit
    ;;
esac

bindir="$prefix/$target/bin"
if test -n $pathadd; then
  pathadd="$pathadd:$bindir"
else
  pathadd="$bindir"
fi

mkdir $builddir
cd $builddir

summary="summary-$1"

echo "== Summary ==" > $summary
echo "Target: $target" >> $summary
echo "gcc $gccver" >> $summary
if test -n "$gccpatch"; then
  echo "gcc patch $gccpatch" >> $summary
fi
echo "binutils $binutils" >> $summary
echo "install in $prefix/$target" >> $summary
echo "when complete, make your PATH include $bindir" >> $summary

cat $summary

if test -f "$dlwhere/binutils-$binutils.tar.bz2"; then
  echo "binutils $binutils already downloaded"
else
  getfile binutils-$binutils.tar.bz2 ftp://ftp.gnu.org/pub/gnu/binutils
fi

if test -f "$dlwhere/gcc-$gccver.tar.bz2"; then
  echo "gcc $gccver already downloaded"
else
  getfile gcc-$gccver.tar.bz2 ftp://ftp.gnu.org/pub/gnu/gcc/gcc-$gccver
fi

if test -n "$gccpatch"; then
  if test -f "$dlwhere/$gccpatch"; then
    echo "$gccpatch already downloaded"
  else
    getfile "$gccpatch" "$gccurl"
  fi
fi

echo "extracting binutils"
tar xjf $dlwhere/binutils-$binutils.tar.bz2
echo "extracting gcc"
tar xjf $dlwhere/gcc-$gccver.tar.bz2

if test -n "$gccpatch"; then
  echo "applying gcc patch"
  patch -p0 < "$dlwhere/$gccpatch"
fi

mkdir build-binu
cd build-binu
../binutils-$binutils/configure --target=$target --prefix=$prefix/$target
make
make install
cd .. # get out of build-binu
PATH="${PATH}:$bindir"
SHELL=/bin/sh # seems to be needed by the gcc build in some cases

mkdir build-gcc
cd build-gcc
../gcc-$gccver/configure --target=$target --prefix=$prefix/$target --enable-languages=c
make
make install
cd .. # get out of build-gcc
cd .. # get out of $builddir

  # end of buildone() function
}

echo ""
echo "Select target arch:"
echo "s   - sh"
echo "m   - m68k"
echo "a   - arm"
echo "all - all three compilers"

arch=`input`

case $arch in
  [Ss])
    buildone $arch
    ;;
  [Mm])
    buildone $arch
    ;;
  [Aa])
    buildone $arch
    ;;
  all)
    echo "build ALL compilers!"
    buildone s
    cleardir $builddir

    buildone m
    cleardir $builddir

    buildone a

    # show the summaries:
    cat $builddir/summary-*
    ;;
  *)
    echo "unsupported architecture option"
    exit
    ;;
esac

echo "done"
echo ""
echo "Make your PATH include $pathadd"
