#!/bin/bash

unamestr=$(uname)

if [ "$unamestr" == "Linux" ]; then
    g++ -std=c++11 ./src/main.cpp -I./include $(pkg-config --cflags --static --libs glfw3) -L/path/to/opengl/lib -lGL -o main.o
elif [ "$unamestr" == "Darwin" ]; then
    g++ -std=c++11 ./src/main.cpp -I./include $(pkg-config --cflags --static --libs glfw3) $(pkg-config --libs --cflags glew glm) -framework OpenGL -o main.o
fi