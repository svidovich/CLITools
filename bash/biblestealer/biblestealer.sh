#!/bin/bash
printf "How many times is Jesus said in the bible? "
cat bible.txt | grep -o Jesus | wc -l

