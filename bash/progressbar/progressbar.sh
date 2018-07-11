#!/bin/bash

printf "		     Progress\n"
for (( i = 1; i<= 100; i++ ));
do
	if (( $i <= 10 ))
	then
		tput setaf 1; printf "▒";
	elif (( $i > 15 && $i <= 25 ))
	then
		tput setaf 3; printf "▒";
	elif (( $i > 35 && $i <= 45 ))
        then    
                tput setaf 2; printf "▒";
	elif (( $i > 65 && $i <= 75 ))
	then
		tput setaf 6; printf "▒";
	elif (( $i > 85 && $i < 94 ))
	then
		tput setaf 4; printf "▒";
	elif (( $i == 100 ))
	then
		tput setaf 4; printf "▒\n";
		tput setaf 7; printf "Done.\n";
	else
		true	
        fi;
	sleep 0.1
done
