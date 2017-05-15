set NAME=magic

g++ -o %NAME% grader.cpp assistant.cpp magician.cpp -O2 -lm -std=c++11