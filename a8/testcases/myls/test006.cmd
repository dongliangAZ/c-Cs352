vgopts=$1
outfile=$2
errfile=$3
statusfile=$4

ulimit -t 5
thisdir=`pwd`
cd myls-test-dir
valgrind $vgopts -q $thisdir/myls SpecialCharFilenames >${outfile}  2>${errfile}

exitstatus=$?
echo $exitstatus > $statusfile
