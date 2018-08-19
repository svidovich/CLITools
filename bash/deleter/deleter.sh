#!/bin/bash
CURRENTTIME=`date +"%s"`
THEFILES=`find . -mindepth 2 -type f`
for file in $THEFILES
do
	FILETIME=`date -r $file +"%s"`
	if (( $CURRENTTIME - $FILETIME > 86400 ));
	then > $file
	fi
done
