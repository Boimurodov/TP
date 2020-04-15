#!/bin/bash
cd $1 &> /dev/null
mkdir $3 &> /dev/null
for chmod + x file in $(ls -l)
do
if [[ $file == *.$2 ]]
then
cp $file $3/ &> /dev/null
fi
done
tar -czvf $4 $3 &> /dev/null
echo done


