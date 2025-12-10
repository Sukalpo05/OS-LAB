# Shell Script Notes

A concise and practical reference for common Bash scripting features: arrays, strings, input handling, arithmetic, and conditionals. All examples are written for **Bash** and are suitable for both scripting practice and exams.

---

## 📌 Arrays

### **Declare an Array**
```bash
arr=( 1 2 3 4 )
Access an Index
bash
Copy code
echo ${arr[2]}
Print All Values
bash
Copy code
echo ${arr[*]}
Array Length
bash
Copy code
echo ${#arr[*]}
Append Values
bash
Copy code
arr+=( 5 6 7 )
Associative Arrays
bash
Copy code
declare -A myArray
myArray=( [name]=Paul [age]=20 )
echo "${myArray[name]}"
📌 Strings
Declare a String
bash
Copy code
myVar="Hello World!"
Length of String
bash
Copy code
length=${#myVar}
Uppercase Conversion
bash
Copy code
upper=${myVar^^}
Lowercase Conversion
bash
Copy code
lower=${myVar,,}
Substring Replacement
bash
Copy code
replace=${myVar/World/Buddy}
Slice a String
bash
Copy code
slice=${myVar:6:11}
📌 User Input
Basic Input
bash
Copy code
read var_name
Input With Prompt
bash
Copy code
read -p "Your name: " NAME
📌 Arithmetic Operations
Using let
bash
Copy code
let a++
let a=5*10
Example
bash
Copy code
a=10
b=5
let sum=a+b
let diff=a-b

echo "Sum: $sum"
echo "Difference: $diff"
Using Double Parentheses (( ))
Inline Calculation
bash
Copy code
echo "Sum: $((a+b))"
Assigning Values
bash
Copy code
a=10
b=5

(( sum = a + b ))
(( diff = a - b ))

echo "Sum: $sum"
echo "Difference: $diff"
📌 Conditional Statements
Basic If–Else
bash
Copy code
if [ $marks -gt 40 ]
then
    echo "You are PASS"
else
    echo "You are FAIL"
fi
Comparison Operators
Operator	Meaning
-eq / ==	Equal
-ge	Greater than or equal
-le	Less than or equal
-ne / !=	Not equal
-gt	Greater than
-lt	Less than

If–Elif–Else
bash
Copy code
if [ $marks -ge 80 ]
then
    echo "First Division"
elif [ $marks -ge 60 ]
then
    echo "Second Division"
else
    echo "Fail"
fi
