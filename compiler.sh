#!/bin/bash
echo "Bash version ${BASH_VERSION}..."
gcc -o $1 $1.c
echo "Excuted: gcc -o $1 $1.c"
