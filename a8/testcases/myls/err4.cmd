outfile=$1
errfile=$2
statusfile=$3

myls  NoReadPermissionDir  >${outfile}  2>${errfile}

exitstatus=$?
echo $exitstatus > $statusfile
