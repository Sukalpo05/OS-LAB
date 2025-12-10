INTRODUCTION TO SHELL SCRIPT

➡️ ARRAY

arr=( 1 2 3 4 )

1) TO GET A PARTICULAR INDEX IN ARRAY

echo ${arr[2]}
 
2) TO GET ALL VALUES
 
echo ${arr[*]}
 
3) TO GET LENGTH OF ARRAY

echo ${#arr[*]}

4)UPDATE THE ARRAY

arr+=( 5 6 7 )

5) KEY VALUE PAIRS IN ARRAY

declare -A myArray
myArray=( [name]=Paul [age]=20 )
echo "${myArray[name]}"

➡️ STRINGS
 
myVar="Hello World!"

length=${#myVar}

upper=${myVar^^}

lower=${myVar,,}

replace=${myVar/World/Buddy}  (var name, whom, to what)

slice=${myVar:6:11} (var name, start , how many characters)

➡️ USER INPUT

read <var_name>

read -p "Your name" NAME

➡️ ARITHMETIC OPERATIONS

1) Using let command

let a++
let a=5*10

EXAMPLE- 
a=10
b=5
let sum=a+b
let diff=a-b

echo "Sum: $sum"
echo "Difference: $diff"

2) USING DOUBLE BRACKETS

echo "Sum: $((a+b))"

or

a=10
b=5

(( sum = a + b ))
(( diff = a - b ))

echo "Sum: $sum"
echo "Difference: $diff"

➡️ CONDITIONAL STATEMENTS

1) BASIC IF-ELSE

if [ $marks -gt 40 ]     ### NOTE THE SPACE USED, BEFORE AND AFTER , '-gt' is '>' symbol  
then

	echo "You are PASS"

else

	echo "You are FAIL"

fi

2) CHART -

Equal -eq / ==
Greaterthanorequalto -ge
Lessthanorequalto -le
Not Equal -ne / !=
Greater Than -gt
Less Than -lt

3) MULTIPLE CONDITION WITH IF ELIF ELSE

if [ $marks -ge 80 ]
then
	echo "First Division""
elif [ $marks -ge 60 ]
then
	echo "Second Division"
else
	echo "Fail""
fi

➡️ SWITCH CASE 
1) Basic: ";;"  works like a break statement , cases are given in " <case>) " format and "*)" for default

echo "Enter a number:"
read n

case $n in
    1)
        echo "One"
        ;;
    2)
        echo "Two"
        ;;
    3)
        echo "Three"
        ;;
    *)
        echo "Invalid"
        ;;
esac


2) Multiple Matches for Same Case: "|" is the OR symbol

read fruit

case $fruit in
    apple|Apple)
        echo "Red or green."
        ;;
    mango|Mango)
        echo "King of fruits."
        ;;
    banana|Banana)
        echo "Yellow fruit."
        ;;
    *)
        echo "Unknown fruit."
        ;;
esac

3) Ranges & Patterns

read marks

case $marks in
    9[0-9]|100)
        echo "A+"
        ;;
    8[0-9])
        echo "A"
        ;;
    7[0-9])
        echo "B"
        ;;
    *)
        echo "Fail"
        ;;
esac

4)  can use system commands

echo "1. Show date"
echo "2. List files"
echo "3. Current path"
echo -n "Enter choice: "
read c

case $c in
    1)
        date
        ;;
    2)
        ls -l
        ;;
    3)
        pwd
        ;;
    *)
        echo "Invalid choice"
        ;;
esac
➡️ JOINING CONDITIONS

if [ $a -gt 10 ] && [ $b -lt 5 ]; then
    echo "Yes"
else
    echo "No"
fi

OR

if [[ $a -gt 10 && $b -lt 5 ]]; then
    echo "Both conditions true"
else
    echo "Condition failed"
fi


➡️ TERNARY OPERATOR

condition1 && condition2 || condition3

Execute condition2 only when 1 is true else execute condtion3

➡️ LOOPS

1) Using raw numbers: 
for i in 1 2 3 4 5
do

echo "Number is $i"

done

#############################
Other ways to write For loop
############################

2) Using Strings: 

for j in Subhajit Roy
do

echo "Name is $j"

done
>>>>
Name is Subhajit
Name is Roy

3)  Using ".."

for p in {1..20}
(it goes from 1 to 20)

4) Reading from files: 

items="file.txt"

for item in $(cat $items)  /// cat-  gives the content and for loop iterates it
do

echo $item

done

5) Reading array: 

arr=(10 20 30 40)

for val in "${arr[@]}"; do
    echo "$val"
done

#### difference between arr[@] and arr[*]

"${arr[@]}" → expands to each element as a separate word
"${arr[*]}" → expands to ONE SINGLE STRING

6) Computational for loop

for ((i=0;i<l;i++))
do
	echo $i
done

➡️ WHILE LOOP

count=0
num=10

while [ $count -le $num ]
do

	echo "Numbers are $count"
	let count++

done

#INFINITE LOOP

while true
do

	echo "Hi'

	sleep 2s

done

➡️ To read content from a file

while read myVar
do

	echo $myVar

done < filename

