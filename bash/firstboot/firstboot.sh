#!/bin/bash

# We assume that you are connected to the internet.
printf "Would you like to update, or install popular programs?\n1. Update\n2. Install\n"
read choice
if [ $choice == 1 ]
then
	apt update
	apt upgrade
elif [ $choice == 2 ]	
then
	apt update
	apt upgrade
	apt install vim tmux docker python python3-pip virtualenv nmap tshark
else
	printf "\nBad input.\n"
fi
