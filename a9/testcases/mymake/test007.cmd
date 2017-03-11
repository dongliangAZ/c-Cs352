vgopts=$1    # Valgrind options
outfile=$2
errfile=$3
statusfile=$4

BASEDIR="/home/cs352/spring16/Assignments/assg09/testcases/./mymake"

ulimit -t 10
valgrind $vgopts -q ./mymake ${BASEDIR}/mfile5 t2 >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile
