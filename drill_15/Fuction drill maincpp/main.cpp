#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"


double one(double x) { return 1; };
double two(double x) {	return x / 2;}
double sloping_cos(double d) { return ((d/2)+cos(d)); }
int main() {
	using namespace Graph_lib;
	const int x_max = 600, 
			  y_max = 600; 
	const int x_scale = 20,
			  y_scale = 20;


	Graph_lib::Point kpont{ 300,300 };
	
	Simple_window fukuplice{ Point{100,100},x_max,y_max,"Function graphs" };

	Axis ax{ Axis::x, kpont,400,20,"x axis" };
	ax.set_color(Color::red);
	Axis ay{ Axis::y, kpont,400,20,"y axis" };
	ay.set_color(Color::red);

	const int orig_x = 300,
			  orig_y = 300;
	Point orig(orig_x, orig_y);

	Function funk1(one, -10, 11, orig, 400, x_scale, y_scale);
	//Function funk2([](double x) {return x; }, -10, 11, Graph_lib::Point(300, 300), 400);
	funk1.set_color(Color::cyan);

	Function funk2(two, -10, 11, orig, 400, x_scale, y_scale);
	funk2.set_color(Color::blue);
	
	Graph_lib::Text text1(Point( (orig_x-(10*x_scale)), orig_y+(two(10*y_scale))-20), "x/2");
	text1.set_color(Color::black);


	Function funk3([](double x) {return x * x; }, -10, 11, orig, 400, x_scale, y_scale);
	Function funk4([](double x) {return cos(x); }, -10, 11, orig, 400, x_scale, y_scale);
	funk3.set_color(Color::dark_magenta);
	funk4.set_color(Color::blue);
	Function funk5(sloping_cos, -10, 11, orig, 400, x_scale, y_scale);
	funk5.set_color(Color::dark_yellow);

	fukuplice.attach(funk5);
	fukuplice.attach(text1);
	fukuplice.attach(funk1); 
	fukuplice.attach(funk2);
	fukuplice.attach(funk3);
	fukuplice.attach(funk4);
	fukuplice.attach(ay);
	fukuplice.attach(ax);
	fukuplice.wait_for_button();


}