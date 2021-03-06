vgopts=$1    # Valgrind options
outfile=$2
errfile=$3
statusfile=$4

BASEDIR="/home/cs352/spring16/Assignments/assg10/testcases/./mymake"
rm -f _testTarg*
rm -f _testDep*
echo "original 1" > _testTarg1
echo "original 2" > _testTarg2
echo "original 3" > _testTarg3
echo "original 4" > _testTarg4
touch -t 160501011055.01 _testTarg1
touch -t 160501011057.01 _testTarg2
touch -t 160501011021.01 _testTarg3
touch -t 160501011055.01 _testTarg4
touch -t 160501011044.01 _testDep5
touch -t 160501011018.01 _testDep4
touch -t 160501011044.01 _testDep2
touch -t 160501011043.01 _testDep3
touch -t 160501011011.01 _testDep1
#rm -f _testTarg1
#rm -f _testTarg2
#rm -f _testTarg3
rm -f _testTarg4

ulimit -t 10
valgrind $vgopts -q ./mymake ${BASEDIR}/mfile6 _testTarg3 >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile
cat _testTarg1 >> ${outfile}
cat _testTarg2 >> ${outfile}
cat _testTarg3 >> ${outfile}
#cat _testTarg4 >> ${outfile}
rm -f _testTarg*
rm -f _testDep*
