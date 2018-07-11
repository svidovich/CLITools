#!/bin/bash

#GREEN = '\033[0;32m'
for (( i = 1; i <= 100; i++  )); 
do
	printf '\r%2d' "$i";
	printf "/100";
	sleep 0.1;
	if
		[ $i == 100 ]
		then
			tput setaf 2; echo -e "\nDone.\n";
	fi;
done
