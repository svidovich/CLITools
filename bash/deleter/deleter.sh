#!/bin/bash
# This is Unix time at execution
CURRENTTIME=`date +"%s"`
# Find files only in subdirectories. You can change this by modifying
# the mindepth parameter.
THEFILES=`find . -mindepth 2 -type f`
# For every file in the files found,
for file in $THEFILES
do
	# Figure out when it was created
	FILETIME=`date -r $file +"%s"`
	# If it's more than 24 hours old,
	if (( $CURRENTTIME - $FILETIME > 86400 ));
	# Truncate it, but keep the file in place.
	then rm $file
	fi
done
