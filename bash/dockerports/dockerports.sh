#!/bin/bash

# This script assumes that you have already run and set up your ftp server with docker-compose.
# First, let's put the ftp server up!
docker-compose up -d

# docker ps shows all of the containers and the hosts they occupy. The output is piped to
# FNR > 1 skips the first line. The output is piped to
# -F':' specifies the field separator as a colon, which identifies the port; the output is piped to
# -F'>' specifies the field separator as greater-than, since ports usually look like abcd->efgh in docker ps. Everything after this is piped to
# -F' ' specifies the field separator as a space, which separates PORTS from NAMES. The output is piped to
# '/^[[:space:]]*$/d which removes whitespace. The output is piped to
# ports.txt, the file in which the resultant port is saved.

docker ps | awk 'FNR > 1' | awk -F':' '{print $2}' | awk -F'>' '{print $2}' | awk -F' ' '{print $1}' | sed '/^[[:space:]]*$/d' > ports.txt

# We will archive but NOT compress the output file. c: create, f: filename.
# To compress, add -z.
# To add to an archive, you can use tar --append --file=archivename.tar filename.ext
tar -cf dockerports.tar ports.txt

# Next, let's set up the variables we will need to upload to the ftp server.
HOST='0.0.0.0'
USER='vivec'
PASSWD='f'
FILE='dockerports.tar'

ftp -nv4 $HOST <<END_SCRIPT
quote USER $USER
quote PASS $PASSWD
binary
put $FILE
quit
END_SCRIPT

# Let's turn the ftp server off.
docker-compose down
