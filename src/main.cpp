//#define GL_SILENCE_DEPRECATION
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../include/core/window.hpp"

#include <iostream>

int main(void) {
    GLFWwindow* window;

    if (!glfwInit())
        return EXIT_FAILURE;

    window = glfwCreateWindow(1080, 720, "AeroUI", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}