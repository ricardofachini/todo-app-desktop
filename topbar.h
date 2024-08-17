//
// Created by ricardofachini on 14/08/24.
//
#include <leif/leif.h>

#ifndef TOPBAR_H
#define TOPBAR_H
#define WIN_MARGIN 20.0f

static int win_width = 1280, win_height = 720;

static void render_topbar(void) {
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
        props.corner_radius = 5.0f;



        lf_push_style_props(props);
        lf_set_line_should_overflow(false);
        lf_button_fixed("Nova tarefa", width, -1);
        lf_set_line_should_overflow(true);
        lf_pop_style_props();
    }
}

#endif //TOPBAR_H
