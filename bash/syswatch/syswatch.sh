#!/bin/bash

printf "Hello %s. Welcome to syswatch.\n" "$USER"
run=true
while [ $run ]
	do
		printf "Menu\n1. Memory Info\n2. Disk Usage\n3. Exit\n"
		printf "Make your selection: "
		read input
		if [ "$input" = "3" ]; then
			break
		elif [ "$input" = "1" ]; then
			cat /proc/meminfo
		elif [ "$input" = "2" ]; then
			df -h
		fi
	done
printf "\nGoodbye.\n"
