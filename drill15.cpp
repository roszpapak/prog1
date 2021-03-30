/*g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
     
#include "Simple_window.h"
#include "Graph.h"

double one (double x) {return 1;};

double slope (double x) {return x/2;};

double square(double x) {return x*x;};

double cosine(double x) {return cos(x);};

double sloping_cos(double x) {return cos(x)+slope(x);};

int main() {


	Simple_window win {Point{100,100}, 600, 600, "Function graphs"};

	int xlength=400;
	int ylength=400;

	int x_orig=600/2;
	int y_orig=600/2;

	Point origo(x_orig,y_orig);

	int xscale=20;
	int yscale=20;

	Axis x {Axis::x,Point{20,y_orig},xlength,xlength/xscale,"x"};

	Axis y {Axis::y,Point{x_orig,ylength+20},ylength,ylength/yscale,"y"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	Function o(one, -10,11,origo, 400,20,20);
	Function sq(square,-10,11,origo,400,20,20);
	Function s(slope,-10,11,origo,400,20,20);
	Function c(cosine,-10,11,origo,400,20,20);
	c.set_color(Color::blue);
	Function sc(sloping_cos,-10,11,origo,400,20,20);

	Text ts(Point(100,y_orig+80),"x/2");

	win.attach(sc);
	win.attach(c);
	win.attach(ts);
	win.attach(s);
	win.attach(sq);
	win.attach(o);
	win.attach(x);
	win.attach(y);
	    	
	win.wait_for_button();
}