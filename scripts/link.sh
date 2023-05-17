# !bin/bash

g++ -std=c++11 ../src/main.cpp `pkg-config --cflags --static --libs glfw3` `pkg-config --libs --cflags glew glm` -framework OpenGL