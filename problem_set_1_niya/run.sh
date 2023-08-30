#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++ "$1" -o "${1%.cpp}"
./"${1%.cpp}" < in.txt > out.txt
diff_output=$(diff out.txt sol.txt)
echo "$diff_output"
exit 0