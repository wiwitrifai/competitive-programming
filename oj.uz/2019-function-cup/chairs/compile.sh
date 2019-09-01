#!/bin/bash

problem=chairs

g++-7 -Wall -lm -static -DEVAL -o "${problem}" -O2 "grader.cpp" "king.cpp" "vassal.cpp"
