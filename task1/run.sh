dir_for_backup="$1"
file_extension="$2"
output_folder="$3"
output_archive_name="$4"

$(mkdir $output_folder)

for file in $(find "$dir_for_backup" -name "*.$file_extension")
do
	$(cp --backup=numbered "$file" "$output_folder")
done
$(tar -czf "$output_archive_name" "$output_folder")
echo "done"

