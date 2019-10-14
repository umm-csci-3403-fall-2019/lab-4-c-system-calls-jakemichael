#!/usr/bin/env bash

a=$1

files=$(find $a -type f | wc -l)
directories=$(find $a -type d | wc -l)

echo "There were" $directories "directories."
echo "There were" $files "regular files." 
