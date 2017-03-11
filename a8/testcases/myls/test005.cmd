vgopts=$1
outfile=$2
errfile=$3
statusfile=$4

BASEDIR="/home/cs352/spring16/Assignments/assg08/testcases/myls"

ulimit -t 5
thisdir=`pwd`
valgrind $vgopts -q $thisdir/myls ${BASEDIR}/myls-test-dir >${outfile}  2>${errfile}

exitstatus=$?
echo $exitstatus > $statusfile
