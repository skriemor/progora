#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"
/*
Felhasznalva rbesenczi repobol:header fajlok,
valamint Graph.cpp, GUI.cpp, Simple_window.cpp, Window.cpp
*/


int main() {
	using namespace Graph_lib;
	const int x_max = 1000, 
			  y_max = 800; //1000x800-as ablak
	int gridx=y_max / 8, //a grid csak a 800/800as teruletre fekszik
		gridy = y_max / 8;  // 800x800as kivalasztott terulet nyolcadolva
	
	Simple_window fukuplice{ Point{100,100},x_max,y_max,"Canvas" };
	
	
	
	//a grid 
	Lines grid;

	for (int X = gridx; X <= 800; X += gridx) grid.add(Point(X,0), Point(X,800));
	for (int Y = gridy; Y <= 800; Y += gridy) grid.add(Point(0, Y), Point(800, Y));
	grid.set_color(Color::cyan);


	//Az atlosan lerajzolt piros negyzetek
	Vector_ref<Graph_lib::Rectangle> redtangles;
	for (int diag = 0; diag < 800; diag += 100) {
		redtangles.push_back(new Graph_lib::Rectangle(Point(diag, diag), 100, 100));
		redtangles[diag / 100].set_fill_color(Color::red);
		fukuplice.attach(redtangles[diag/100]);
	}

	// 3 masolata a 200x200as kepnek "szabad" helyeken
	Graph_lib::Image img1(Point(200,0),"200200.jpg");
	Graph_lib::Image img2(Point(400, 0), "200200.jpg");
	Graph_lib::Image img3(Point(600, 0), "200200.jpg");




	fukuplice.attach(img1);
	fukuplice.attach(img2);
	fukuplice.attach(img3);
	fukuplice.attach(grid);

	//Itt kovetkezik a mozgo 100x100as kep
	int x = 0, y=0;
	Graph_lib::Image img100(Point(0, 0), "100100.jpg");
	fukuplice.attach(img100);
	for (int y = 0; y < 800; y += 100) {
		for (int x = 0; x < 800; x += 100) {
			if (x!=0)img100.move(100, 0);
			fukuplice.wait_for_button();
		}
		img100.move(-700, 100);
	}
	
}