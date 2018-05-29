set NAME=tile

g++ -o %NAME% grader.cpp %NAME%.cpp -O2 -lm -std=c++11
