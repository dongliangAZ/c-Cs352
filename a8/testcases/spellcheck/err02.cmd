outfile=$1
errfile=$2
statusfile=$3

./spellcheck -d  >${outfile} 2>${errfile}
exitstatus=$?
echo $exitstatus > $statusfile

