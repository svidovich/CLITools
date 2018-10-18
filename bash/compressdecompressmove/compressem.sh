for file in `ls | grep .e`; do
	tar -czvf "$file.tar" $file
done
