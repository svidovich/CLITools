for file in `ls`; do
	uefi-firmware-parser -e $file -o "$file.e"
done
