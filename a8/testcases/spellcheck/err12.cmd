outfile=$1
errfile=$2
statusfile=$3
BASEDIR="/home/cs352/spring16/Assignments/assg08/testcases/spellcheck"

./spellcheck -d ${BASEDIR}/dictfile01 -u -i ${BASEDIR}/infile01 -q  >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile

