outfile=$1
errfile=$2
statusfile=$3
BASEDIR="/home/cs352/spring16/Assignments/assg10/testcases/./mymake"

./mymake ${BASEDIR}/efile4 t1 >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile

