vgopts=$1    # Valgrind options
outfile=$2
errfile=$3
statusfile=$4

BASEDIR="/home/cs352/spring16/Assignments/assg08/testcases/./spellcheck"

ulimit -t 10
valgrind $vgopts -q ./spellcheck -u -i ${BASEDIR}/infile04 -d ${BASEDIR}/dictfile01 | sort  >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile
