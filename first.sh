#echo "hello"
#vech=bus
#n=10
#echo $vech
#echo $n

#mylang=pennyslvania
#echo "i speak $mylang"

#echo "enter the number"
#read choice
#if [ $choice -gt 0 ]
#then
#echo "$choice number is positive"
#else
#echo "$choice number is negative"
#fi

# for i in 1 2 3 4 5
# do 
# echo "Welcome $i times"
# done

# i=1; n=1
# while [ "$i" -le 10 ]
# do
# echo "$n*$i=`expr $i \* $n`"
# i=`expr $i + 1`
# done

# echo "enter choice"
# read var
# case $var in
# 1) echo "one";;
# 2) echo "two";;
# 3) echo "three";;
# 4) echo "four";;
# *) echo "sorry, it is bigger than four";;
# esac

# echo "              CALCULATOR             "
# echo "Enter first number"
# read num1
# echo "Enter second number"
# read num2
# echo "Select the operation you want to perform"
# echo "1. Addition
# 2. Subtraction
# 3. Multiplication
# 4. Division"
# read choice
# case $choice in 
# 1) echo "$num1+$num2=$((num1 + num2))";;
# 2) echo "$num1-$num2=$((num1 - num2))";;
# 3) echo "$num1*$num2=$((num1 * num2))";;
# 4) echo "$num1/$num2=$(echo "scale=2; $num1 / $num2" | bc)";;
# *) echo "Invalid choice";;
# esac

# for ((i=2; i<=20; i+=2))
# do
# echo "$i"
# done

# for i in $(seq 1 1 20)
# do
# if [ $((i % 2)) -eq 0 ]
# then
# echo "$i"
# fi
# done

# for i in $(seq 2 2 20)
# do 
# echo "$i"
# done 

# read var
# echo "${var^^}"

# echo "enter a string"
# read str
# 
# str=$(echo "$str" | tr -d ' ')
# str=$(echo "$str" | tr 'A-Z' 'a-z')
# vowels=$(echo "$str" | grep -o "[aeiou]" | wc -l)
# consonants=$(echo "$str" | grep -o "[bcdfghjklmnpqrstvwxyz]" | wc -l)
# echo "Vowels: $vowels"
# echo "Consonants: $consonants"
