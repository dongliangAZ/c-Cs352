for f in test*; do 
  res="${f/test/result}" 
  cat $f | ./rotstr >$res
  cat $f | ./rotstr 2> $res.err
  echo $? > $res.ret
done
