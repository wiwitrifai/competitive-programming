#!/bin/bash

name="$1"
mkdir $name
cd $name
mv ~/Downloads/Compressed/grader.zip .
unzip grader.zip
