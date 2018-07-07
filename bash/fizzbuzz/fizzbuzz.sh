#!/bin/bash

for (( i = 1; i <= 100; i++ )); 
do
	if [ $(($i % 5)) == 0 ];
	then printf "$i: buzz\n";
	elif [ $(($i % 3)) == 0 ];
	then printf "$i: fizz\n";
	else printf "$i\n";
fi;
done
