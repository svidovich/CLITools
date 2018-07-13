#!/bin/bash

string=$(<thefile.txt)
printf "Text to be reversed:\n$string\n"
length=`expr length "$string"`
printf "The reversed text:\n"
for (( i=-1; i>-$length-1; i-- ));
do
	printf "${string:$i:1}";
done
printf "\n"
