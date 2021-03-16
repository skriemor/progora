#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},


    color_menu{ Point{x_max() - 70,80},70,20,Menu::vertical,"color" },

    //mivel szabad a lambda, hat legyen lambda, remelem nem tul csunya
    //valamiert nem lambdazott CB eseten nem hajlando ext referenciat elfogadni :/
    menu_button{ Point{x_max() - 80,60},80,20, "color menu", [](Address, Address adr) {
    reference_to<Lines_window>(adr).color_menu.show();
  
    } },
    style_menu{ Point{x_max() - 70,220},70,20,Menu::vertical,"style" },
    second_menu_button{ Point{x_max() - 80,200},80,20, "style menu", [](Address, Address adr) {
    reference_to<Lines_window>(adr).style_menu.show();

    } }

{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    attach(lines);

    //lambda-ed button CBs
    color_menu.attach(new Button{ Point{0,0},0,0,"red",[](Address, Address adr) {
        reference_to<Lines_window>(adr).lines.set_color(Color::red);  
        reference_to<Lines_window>(adr).hide_menu();
        reference_to<Lines_window>(adr).redraw();
        } });
    color_menu.attach(new Button{ Point{0,0},0,0,"blue",[](Address, Address adr) {
        reference_to<Lines_window>(adr).lines.set_color(Color::blue);
        reference_to<Lines_window>(adr).hide_menu();
        reference_to<Lines_window>(adr).redraw();
        } });
    color_menu.attach(new Button{ Point{0,0},0,0,"black",[](Address, Address adr) {
        reference_to<Lines_window>(adr).lines.set_color(Color::black);
        reference_to<Lines_window>(adr).hide_menu();
        reference_to<Lines_window>(adr).redraw();
        } });
    style_menu.attach(new Button{ Point{0,0},0,0,"dotted",[](Address, Address adr) {
     reference_to<Lines_window>(adr).lines.set_style(Line_style::dot);
     reference_to<Lines_window>(adr).hide_second_menu();
     reference_to<Lines_window>(adr).redraw();
     } });
    style_menu.attach(new Button{ Point{0,0},0,0,"solid",[](Address, Address adr) {
     reference_to<Lines_window>(adr).lines.set_style(Line_style::solid);
     reference_to<Lines_window>(adr).hide_second_menu();
     reference_to<Lines_window>(adr).redraw();
     } });
    style_menu.attach(new Button{ Point{0,0},0,0,"dashed",[](Address, Address adr) {
     reference_to<Lines_window>(adr).lines.set_style(Line_style::dash);
     reference_to<Lines_window>(adr).hide_second_menu();
     reference_to<Lines_window>(adr).redraw();
     } });


    attach(style_menu);
    attach(color_menu);
    color_menu.hide();
    style_menu.hide();
    attach(menu_button);
    attach(second_menu_button);
        
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}
