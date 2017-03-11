vgopts=$1    # Valgrind options
outfile=$2
errfile=$3
statusfile=$4

BASEDIR="/home/cs352/spring16/Assignments/assg10/testcases/./mymake"

rm -f _testTarg*
rm -f _testDep*
echo "original t1" > _testTarg1
touch -t 160501011000.01 _testDep3
touch -t 160501011001.01 _testTarg1
touch -t 160501011002.01 _testDep2
touch -t 160501011003.01 _testDep4
touch -t 160501011004.01 _testDep1

ulimit -t 10
valgrind $vgopts -q ./mymake ${BASEDIR}/mfile1 _testTarg2 >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile
cat _testTarg2 >> ${outfile}
rm -f _testTarg*
rm -f _testDep*
