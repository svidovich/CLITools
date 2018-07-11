#!/bin/bash

#GREEN = '\033[0;32m'
for (( i = 1; i <= 100; i++  )); 
do
	# This line makes the counter update in place
	printf '\r%2d' "$i";
	# This line prints the total number after it
	printf "/100";
	sleep 0.1;
	if
		# When the counter is done, let's print done in green text
		[ $i == 100 ]
		then
			tput setaf 2; echo -e "\nDone.\n";
	fi;
done
