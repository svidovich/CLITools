#!/bin/bash

printf "Hello %s. Welcome to syswatch.\n" "$USER"
run=true
while [ $run ]
	do
		printf "Menu\n1. Check Memory Usage\n2. Exit\n"
		printf "Make your selection: "
		read input
		printf "You selected %s.\n\n" "$input"
		if [ "$input" = "2" ]; then
			break
		fi
	done
printf "\nGoodbye.\n"
