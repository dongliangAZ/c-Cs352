vgopts=$1
outfile=$2
errfile=$3
statusfile=$4

ulimit -t 5
thisdir=`pwd`
cd myls-test-dir/SpecialCharFilenames
valgrind $vgopts -q $thisdir/myls ')()()()()('  >${outfile}  2>${errfile}

exitstatus=$?
echo $exitstatus > $statusfile
