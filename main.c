#include <GLFW/glfw3.h>
#include "stdio.h"


int main() {
    GLFWwindow* main_window;

    if (!glfwInit()) {
        printf("Erro ao inicializar a janela");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window) {
        // Window or OpenGL context creation failed
        glfwTerminate(); // encerra a janela
        return -1;
    }

    





    glfwTerminate(); // encerra a janela
}