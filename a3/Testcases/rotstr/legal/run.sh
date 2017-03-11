for f in test*; do
  res="${f/test/result}" 
  dir="${f/test/}"
  mkdir $dir
  cat $f | ./rot > $dir/$res
  cat $f | ./rot 2> $dir/$res.err
  echo $? > $dir/$res.ret
  cp $f $dir
done
