echo "Enter the first number: "
read n1
echo "Enter the second number: "
read n2
echo "---------------- CALCULATOR----------------"
echo "Select the operation to be executed:
1. Addition
2. Subtraction
3. Multiplication
4. Division"

read var
case $var in
1) echo "$n1+$n2"=$((n1+n2));;
2) echo "$n1-$n2"=$((n1-n2));;
3) echo "$n1 * $n2 = $(echo "$n1 * $n2" | bc)";;
4) echo "$n1 / $n2 = $(echo "scale=2; $n1 / $n2" | bc)";;
*) echo "Invalid option";;
esac
