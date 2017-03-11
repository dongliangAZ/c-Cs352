for f in test*; do
  res="${f/test/result}" 
  dir="${f/test/}"
  mkdir $dir
  cat $f | ./vowels > $dir/$res
  cat $f | ./vowels 2> $dir/$res.err
  echo $? > $dir/$res.ret
  cp $f $dir
done
