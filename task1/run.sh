#!/bin/bash

#./run.sh <путь к директории> <расширение> <название папки для бэкапа> <имя архива

cd -P $1
mkdir $3

for file in find "$1" -name "*.$2"
do
	cp --backup=numbered "$file" "$3"
done
tar -czf "$4" "$3"
echo "done"
