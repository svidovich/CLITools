mkdir archives
for file in `ls | grep tar`; do
	mv $file archives
done

