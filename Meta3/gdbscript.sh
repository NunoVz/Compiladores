#!/bin/bash

meta="meta3"               # Change this to the meta folder you want to test
executable="./uccompiler"  # Change this to your executable
file_to_test="errors_funcdefinitions.uc"  # Change this to the specific file you want to test

# Full path to the file
full_path="./c/$meta/errors_funcdefinitions/$file_to_test"

# Run the program with GDB
gdb -ex run --args "$executable" -s < "$full_path"

