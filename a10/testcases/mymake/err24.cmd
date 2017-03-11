outfile=$1
errfile=$2
statusfile=$3

BASEDIR="/home/cs352/spring16/Assignments/assg10/testcases/./mymake"

rm -f _testTarg*
rm -f _testDep*
touch -t 160501011001.01 _testDep1
touch -t 160501011001.01 _testDep2
touch -t 160501011002.01 _testDep3
touch -t 160501011003.01 _testDep4

ulimit -t 10
./mymake ${BASEDIR}/efile16 _testTarg1 >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile

rm -f _testTarg*
rm -f _testDep*

