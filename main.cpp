/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main() {


	    Simple_window win {Point{100,100}, 600, 400, "My Window"};

	    Rectangle r {Point{200,200}, 100, 50};

		r.set_fill_color(Color::yellow);
		r.set_style(Line_style(Line_style::dash, 4));

		Text t {Point{200,300}, "Hello graphics!"};
		t.set_font(Font::times_bold);
		t.set_font_size(20);

		Image ii {Point{100,100}, "badge.jpg"};


		Circle c {Point{150,150}, 50};

        Polygon poly;

		poly.add(Point{300,200});
		poly.add(Point{350,100});
		poly.add(Point{400,200});
	
		poly.set_color(Color::red);

		Mark m {Point{100,200},'x'};

		Closed_polyline cpoly;
		cpoly.add(Point{100,50});
		cpoly.add(Point{200,50});
		cpoly.add(Point{200,100});
		cpoly.add(Point{100,100});
		cpoly.add(Point{50,75});

		cpoly.set_fill_color(Color::red);
		
		win.attach(ii);
		win.attach(r);
		win.attach(t);
		win.attach(poly);
		win.attach(c);
		win.attach(m);
		win.attach(cpoly);


	    win.wait_for_button();
}