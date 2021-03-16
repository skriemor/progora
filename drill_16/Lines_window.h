#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	
	

	bool wait_for_button();

private:
	Open_polyline lines;
	
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Menu style_menu;
	Button menu_button;
	Button second_menu_button;

	//hide/show popup in case of selecting buttons within menu / menu callers
	void hide_menu() {
		color_menu.hide();
		menu_button.show();
	}
	void menu_pressed() {
		menu_button.hide();
		color_menu.show();
	}
	void hide_second_menu() {
		style_menu.hide();
		second_menu_button.show();
	}
	void second_menu_pressed() {
		second_menu_button.hide();
		style_menu.show();
	}
	
	
	void next();
	void quit();

	
};