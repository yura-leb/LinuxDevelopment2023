#!/bin/bash

echo "This is a test input file" > test_input.txt
strace -e unlink -e fault=unlink:error=ENOENT ./move test_input.txt test_output.txt > /dev/null 2> /dev/null

if [ $? == 4 ]; then
	echo "Test checked succesfully"
else
	echo "Incorrect failing"
fi
