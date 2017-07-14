#!/bin/bash

for txt in `ls *.txt`; do
    echo remove: $txt
    rm $txt
done
echo "All .txt removed"