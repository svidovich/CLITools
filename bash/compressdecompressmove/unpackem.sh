# You need to do pip install -r requirements.txt for this to work
for file in `ls`; do
	uefi-firmware-parser -e $file -o "$file.e"
done
