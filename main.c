#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include "stdio.h"
#include <leif/leif.h>
#include "topbar.h"

#define WIN_MARGIN 20.0f

//static int win_width = 1280, win_height = 720;


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

        render_topbar();

        lf_next_line();
        {
            static const char* filters[] = {"TODAS", "EM ANDAMENTO", "COMPLETADAS", "BAIXA", "MÉDIA", "ALTA"};

            LfUIElementProps filters_props = lf_get_theme().text_props;
            filters_props.margin_top = 30.0f;
            filters_props.margin_right = 30.0f;

            const float filters_size = sizeof(filters) / sizeof(filters[0]);


            float width = 0.0f;
            float ptr_before = lf_get_ptr_x();
            lf_push_style_props(filters_props);
            lf_set_no_render(true);
            for (uint32_t i = 0; i < filters_size; i++)
            {
                lf_button(filters[i]);
            }
            lf_set_no_render(false);
            width = lf_get_ptr_x() - ptr_before - filters_props.margin_right - filters_props.padding;

            lf_set_ptr_x_absolute(win_width - width - WIN_MARGIN);

            lf_set_line_should_overflow(false);
            for (uint32_t i = 0; i < filters_size; i++)
            {
                lf_push_style_props(filters_props);
                lf_button(filters[i]);
                lf_pop_style_props();
            }
            lf_set_line_should_overflow(true);
        }

        lf_div_end();
        lf_end();


        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    lf_terminate();
    glfwDestroyWindow(window);
    glfwTerminate(); // encerra a janela
}