vgopts=$1    # Valgrind options
outfile=$2
errfile=$3
statusfile=$4

BASEDIR="/home/cs352/spring16/Assignments/assg10/testcases/./mymake"
rm -f _testTarg*
rm -f _testDep*
touch -t 160501011000.01 _testDep1
touch -t 160501011001.01 _testDep2
touch -t 160501011002.01 _testDep3

ulimit -t 10
valgrind $vgopts -q ./mymake ${BASEDIR}/mfile4 _testTarg1 >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile
cat _testTarg1 >> ${outfile}

rm -f _testTarg*
rm -f _testDep*
