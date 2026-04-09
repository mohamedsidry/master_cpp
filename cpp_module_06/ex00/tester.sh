#!/bin/bash


name="./convert"

# style colors :
RED="\033[1;31m"
YELLOW="\033[1;33m"
PURPLE="\033[1;34m"
GREEN="\033[1;32m"
RESET="\033[0m" 



tests=(
" "
"!"
"A"
"Z"
"a"
"z"
"~"
"0"
"64"
"256"
"1024"
"nan"
"nanf"
"+inf"
"-inf"
"+inff"
"-inff"
)



expected=(
"char: ' '
int: 32
float: 32.0f
double: 32.0"

"char: '!'
int: 33
float: 33.0f
double: 33.0

"

"char: 'A'
int: 65
float: 65.0f
double: 65.0
"
"char: 'Z'
int: 90
float: 90.0f
double: 90.0
"
"char: 'a'
int: 97
float: 97.0f
double: 97.0
"
"char: 'z'
int: 122
float: 122.0f
double: 122.0
"
"char: '~'
int: 126
float: 126.0f
double: 126.0
"
"char: Non displayable
int: 0
float: 0.0f
double: 0.0
"
"char: '@'
int: 64
float: 64.0f
double: 64.0
"
"char: impossible
int: 256
float: 256.0f
double: 256.0
"
"char: impossible
int: 1024
float: 1024.0f
double: 1024.0
"
"char: impossible
int: impossible
float: nanf
double: nan
"
"char: impossible
int: impossible
float: nanf
double: nan
"
"char: impossible
int: impossible
float: +inff
double: +inf
"
"char: impossible
int: impossible
float: -inff
double: -inf
"
"char: impossible
int: impossible
float: +inff
double: +inf
"
"char: impossible
int: impossible
float: -inff
double: -inf
"
)


#//TODO: Add more rests test+= (....), expected+=(...)

tests+=(
"42.42"
"2147483647"
"-2147483648"
"2147483648"
"1234567891234567891234567891234567891234"
"999999999999999999999999999999999999999999999999999999999999999999999827277999999999999999999999999999999999999999998272772772887723778347999999992348458844444444444473478223232235574423277288772377834799999999234845884444444444447347822323223558272772772887834799999999234845884444444444447347822323223557449"
)

expected+=(
"char: '*'
int: 42
float: 42.4f
double: 42.4
"
"char: impossible
int: 2147483647
float: 2147483648.0f
double: 2147483647.0
"
"char: impossible
int: -2147483648
float: -2147483648.0f
double: -2147483648.0
"
"char: impossible
int: impossible
float: 2147483648.0f
double: 2147483648.0
"
"char: impossible
int: impossible
float: inff
double: 1234567891234567874083161838938721615872.0
"
"char: impossible
int: impossible
float: inff
double: inf
"
)


echo " ^^^^^^^^^^^^^^^^^ TEST BEGIN ^^^^^^^^^^^^^^^^^ "

for i in "${!tests[@]}"; do 
    input="${tests[$i]}"
    expected_output="${expected[$i]}"

    result=$($name "$input")
    expected_output=$(echo "$expected_output")
    echo -e "${YELLOW}Test: ${PURPLE}'$input'${RESET}"
    if [ "$result" == "$expected_output" ]; then
        echo "Expected:"
        echo "$expected_output"
        echo "Got:"
        echo "$result"
        echo -e "result status : ${GREEN}OK${RESET} ✅"
    else
        echo "Expected:"
        echo "$expected_output"
        echo "Got:"
        echo "$result"
        echo -e "result status : ${RED}KO 🧨 ${RESET}"
    fi

    echo "----------------------"
done

echo " ^^^^^^^^^^^^^^^^^ TEST OVER ^^^^^^^^^^^^^^^^^ "