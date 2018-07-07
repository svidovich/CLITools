#!/bin/bash
for ((i = 33; i<=126; i++ )) 
do 
	printf '%d %b\n' "$i" $(printf '\\%03o' "$i")
done

