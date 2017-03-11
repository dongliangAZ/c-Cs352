outfile=$1
errfile=$2
statusfile=$3
BASEDIR="/home/cs352/spring16/Assignments/assg09/testcases/./mymake"

./mymake ${BASEDIR}/mfile1 t1 t2  >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile

