#!/bin/bash

echo "This is a test input file" > test_input.txt
strace -e openat -P test_output.txt -e fault=openat:error=ENOSPC ./move test_input.txt test_output.txt > /dev/null 2> /dev/null

if [ $? == 3 ]; then
	echo "Test checked succesfully"
else
	echo "Incorrect failing"
fi