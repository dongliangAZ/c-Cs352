for f in test*; do
  res="${f/test/result}" 
  dir="${f/test/}"
  mkdir $dir
  cat $f | ./palindromes > $dir/$res
  cat $f | ./palindromes 2> $dir/$res.err
  echo $? > $dir/$res.ret
  cp $f $dir
done
