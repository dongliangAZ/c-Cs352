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
touch -t 160501011023.01 _testTarg1
touch -t 160501011051.01 _testTarg2
touch -t 160501011033.01 _testTarg3
touch -t 160501011058.01 _testTarg4
touch -t 160501011012.01 _testDep5
touch -t 160501011022.01 _testDep4
touch -t 160501011053.01 _testDep2
touch -t 160501011059.01 _testDep3
touch -t 160501011014.01 _testDep1
#rm -f _testTarg1
#rm -f _testTarg2
#rm -f _testTarg3
#rm -f _testTarg4

ulimit -t 10
valgrind $vgopts -q ./mymake ${BASEDIR}/mfile7 _testTarg1 >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile
cat _testTarg1 >> ${outfile}
cat _testTarg2 >> ${outfile}
cat _testTarg3 >> ${outfile}
cat _testTarg4 >> ${outfile}
#rm -f _testTarg*
#rm -f _testDep*
