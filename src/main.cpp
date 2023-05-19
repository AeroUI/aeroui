//#define GL_SILENCE_DEPRECATION
#define GLEW_STATIC
#define AUI_NO_DEPRECATION

#include "Core/AeroWindow.hpp"
#include "Input/AeroInput.hpp"
#include "AeroTypes.hpp"

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

        if ((glfwGetKey(window, static_cast<int>(AeroUI::AeroKeyCodes::AERO_KEY_E))) == GLFW_PRESS) {
            std::cout << "pressed\n";
        }
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}