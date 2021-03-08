#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"



int main() {
	using namespace Graph_lib;
	const int x_max = 600, 
			  y_max = 400; //1000x800-as ablak

	//Axis
	Simple_window fukuplice{ Point{100,100},x_max,y_max,"Canvas" };
	Axis ax{ Axis::x, Point{200,300},280,10,"x axis" };
	ax.set_color(Color::black);
	Axis ay{ Axis::y, Point{200,300},280,10,"y axis" };
	ay.set_color(Color::black);
	//Funkcio
	Function szinusz{ sin, 0, 100, Point{20,150}, 1000,50,50 };
	szinusz.set_color(Color::black);

	//Poly
	Graph_lib::Polygon komt;
	komt.add(Point(300, 200)); komt.add(Point(350, 100)); komt.add(Point(400, 200));
	komt.set_color(Color::blue);


	//Rec

	Graph_lib::Rectangle rec(Point(200,200),100,50);
	rec.set_color(Color::red);

	//CPolyLine

	Closed_polyline polline;





	polline.add(Point(100, 50));
	polline.add(Point(200, 50));
	polline.add(Point(200, 100));
	polline.add(Point(100, 100));
	//polline.add(Point(300, 100)); //otodidik pont
	polline.set_color(Color::green);




	polline.set_fill_color(Color::cyan);
	komt.set_style(Line_style(Line_style::dash,4));


	fukuplice.attach(polline);
	fukuplice.attach(rec);
	fukuplice.attach(komt);
	fukuplice.attach(szinusz);
	fukuplice.attach(ay);
	fukuplice.attach(ax);
	fukuplice.wait_for_button();


}