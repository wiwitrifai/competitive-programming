#!/bin/bash

problem=hiccup

g++ -Wall -lm -static -DEVAL -o "${problem}" -O2 "grader.cpp" "${problem}.cpp"
