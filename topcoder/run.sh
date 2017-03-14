#!/bin/bash

fullname="$1"
extension="${fullname##*.}"
filename="${fullname%.*}"
echo "$filename" "$extension"
if [ "$extension" = "cpp" ]; then
  g++ "$fullname" -o e
  if [ $? ]; then
   echo "compiled"
   ./e
   rm e
  else
    echo "compile failed"
  fi
elif [ "$extension" = "java" ]; then
  javac "$fullname"
  if [ $? ]; then 
    echo "compiled"
    java "$filename"
    rm "$filename"".class"
  else
    echo "compile failed"
  fi
elif [ "$extension" = "py" ]; then
  python3 "$fullname"
else
  echo "extension '.$extension' is not defined"
fi