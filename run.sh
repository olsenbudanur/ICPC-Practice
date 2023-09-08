#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++ -o ex.out "$1" -std=c++11
./ex.out < in.txt > out.txt
diff_output=$(diff out.txt sol.txt)
echo "$diff_output"
exit 0