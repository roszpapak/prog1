/*
/*
    g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    Simple_window win {Point{100,100},1000,800,"Canvas"};

    Image ii (Point{200,0},"badge.jpg");
	ii.set_mask(Point{200,200},200,200);

	Image ii2 (Point{100,300},"badge.jpg");
	ii2.set_mask(Point{200,200},200,200);

	Image ii3 (Point{100,500},"badge.jpg");
	ii3.set_mask(Point{200,200},200,200);

	Image ii4 (Point{300,500},"badge.jpg");
    ii4.set_mask(Point{200,200},200,200);
    
    /*int x_grid=100;
    int y_grid=100;
    
    Lines grid;
    for(int x = 100;x <= 800;x+=x_grid){
    	grid.add(Point(x,0),Point(x,800));
    }
    
    for(int y = 100; y <=800; y+=y_grid){
    	grid.add(Point(0,y),Point(800,y));
    }
    
    */
    Vector_ref<Rectangle>vr;
    
    for (int i = 0 ; i<8; i++){
    	for(int j = 0 ; j<8; j++){
    		vr.push_back(new Rectangle(Point(i*100,j*100),100,100));
    		if (i == j){
  			vr[vr.size()-1].set_fill_color(Color::red);
    		}
    		win.attach(vr[vr.size()-1]);
    	}
    }
    
    
    
    //win.attach(grid);
    win.attach(ii);
    win.attach(ii2);
    win.attach(ii3);
    win.attach(ii4);

    Image im (Point{100,0},"badge.jpg");
	im.set_mask(Point{150,150},100,100);



    for (int i =100 ; i <= 800 ; i+=100){
    	for(int j=100; j <= 800; j+=100){

    		if(i==100 && j==100){
    			j+=100;
    		}

    		win.attach(im);
    		win.wait_for_button();
    		im.move(100,0);
    		if (j==i-100){
    			im.move(100,0);
    			j+=100;}
    		
    	}
    	im.move(-800,100);
    	win.attach(im);
    }
    

}
