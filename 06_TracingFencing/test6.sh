#!/bin/bash

echo "This is a test input file" > PROTECTED_test_input.txt
LD_PRELOAD=./libprotect.so ./move PROTECTED_test_input.txt test_output.txt > /dev/null 2> /dev/null

if cmp PROTECTED_test_input.txt test_output.txt
    then echo "Test checked succesfully"
else echo "Incorrect failing"
fi