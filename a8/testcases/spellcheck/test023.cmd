vgopts=$1    # Valgrind options
outfile=$2
errfile=$3
statusfile=$4

BASEDIR="/home/cs352/spring16/Assignments/assg08/testcases/./spellcheck"

ulimit -t 10
valgrind $vgopts -q ./spellcheck -d ${BASEDIR}/dictfile02 < ${BASEDIR}/infile03 | sort  >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile
