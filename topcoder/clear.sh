#!/bin/bash

for txt in `ls *.txt`; do
    echo - $txt
    rm $txt
    source_code="${txt%.*}.cpp"
    echo "  $source_code -> archive"
    mv $source_code 'arcive'
done
echo "All done!"