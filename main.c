#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include "stdio.h"
#include <leif/leif.h>

#define WIN_MARGIN 20.0f

static int win_width = 1280, win_height = 720;


int main() {
    GLFWwindow* main_window;

    if (!glfwInit()) {
        printf("Erro ao inicializar a janela");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Todo APP", NULL, NULL);
    if (!window) {
        // Window or OpenGL context creation failed
        glfwTerminate(); // encerra a janela
        return -1;
    }

    glfwMakeContextCurrent(window);

    lf_init_glfw(win_width, win_height, window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 0.8f);

        lf_begin();

        lf_div_begin(
                ((vec2s) {
                    WIN_MARGIN,
                    WIN_MARGIN
                }), 
                ((vec2s) {
                    win_width - WIN_MARGIN * 2.0f, win_height - WIN_MARGIN * 2.0f
                }), 
                true);
        lf_text("Lista de tarefas");

        lf_end();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    lf_terminate();
    glfwDestroyWindow(window);
    glfwTerminate(); // encerra a janela
}