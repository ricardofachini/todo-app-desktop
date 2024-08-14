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

        {
          static const float width = 160.0f;

          lf_set_ptr_x_absolute(win_width - width - WIN_MARGIN * 2.0f);
          LfUIElementProps props = lf_get_theme().button_props;


          props.margin_left = 0.0f;
          props.margin_right = 0.0f;
          // estilização botao
          props.color = (LfColor){65, 167, 204, 255};
          props.border_width = 0.0f;
          props.corner_radius = 4.0f;



          lf_push_style_props(props);
          lf_set_line_should_overflow(false);
          lf_button_fixed("Nova tarefa", width, -1);
          lf_set_line_should_overflow(true);
          lf_pop_style_props();
        }

        lf_end();


        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    lf_terminate();
    glfwDestroyWindow(window);
    glfwTerminate(); // encerra a janela
}