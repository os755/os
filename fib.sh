a=0
b=1
echo "Fibonacci sequence"
for i in $(seq 1 10)
do
echo "$a"
fn=$((a+b))
a=$b
b=$fn
done
