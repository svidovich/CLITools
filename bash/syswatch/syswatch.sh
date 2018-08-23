#!/bin/bash

printf "Hello %s. Welcome to syswatch.\n" "$USER"
run=true
while [ $run ]
	do
		printf "Menu\n1. Memory Info\n2. Disk Usage\n3. Processor Usage\n4. Exit\n"
		printf "Make your selection: "
		read input
		if [ "$input" = "4" ]; then
			break
		elif [ "$input" = "1" ]; then
			printf "\nDoing cat /proc/meminfo:\n"
			cat /proc/meminfo
		elif [ "$input" = "2" ]; then
			printf "\nDoing df -h:\n"
			df -h
		elif [ "$input" = "3" ]; then
			printf "\nDoing ps -eo pid,pcpu | sort -k 1 -nr | head -10:\n"
			printf "PID   PCPU\n"
			ps -eo pid,pcpu | sort -k 2 -nr | head -10
		fi
	done
printf "\nGoodbye.\n"
