outfile=$1
errfile=$2
statusfile=$3
BASEDIR="/home/cs352/spring16/Assignments/assg08/testcases/spellcheck"

./spellcheck -i ${BASEDIR}/infile01 -d ${BASEDIR}/dictfile01 -i ${BASEDIR}/infile02   >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile

