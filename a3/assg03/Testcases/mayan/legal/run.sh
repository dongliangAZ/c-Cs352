for f in test*; do
  res="${f/test/result}" 
  cat $f | ./mayan >$res
  cat $f | ./mayan 2> $res.err
  echo $? > $res.ret
done
