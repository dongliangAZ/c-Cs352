outfile=$1
errfile=$2
statusfile=$3

myls  . .. ../..  >${outfile}  2>${errfile}

exitstatus=$?
echo $exitstatus > $statusfile
