#!/bin/bash

cd -P $1
mkdir $3 
cp -r $1/*.$2 $1/*/*.$2 --force --backup=numbered $1/$3 
tar -czfv $4 $3
echo "done"

