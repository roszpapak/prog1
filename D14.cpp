#include "std_lib_facilities.h"

struct A {
	virtual void pvf() = 0;
};


 struct B :A{

 	virtual void vf() const{cout << "B::vf()\n";}
 	void f() const {cout << "B::f()\n";}
 	void pvf(){cout << "B:pvf()\n";}
 	
};


struct D : B {
 public:
 	void vf() const override {cout << "D:vf()\n";}
 	void f() {cout << "D:f()\n";}

};


struct D2 : D {

public: 
	void pvf() override {cout << "D2:pvf\n";}

};

struct B2 : B {

public: 
	void pvf() override {cout << "D2:pvf\n";}

};


struct D21 : B2 {

public: 
	string str = "sziamia";
	void pvf () {cout << str << endl;}

};


struct D22 : B2 {

public: 
	int i = 1;
	void pvf () {cout << i << endl;}

};

void f(B2& ref){

	ref.pvf();
}



int main() {

	B b;
	D d;
	D2 d2;
	D21 d21;
	D22 d22;
	
	B& dr = d;

	b.vf();
	b.f();
	cout << "Drill 1\n"; 
	
	d.vf();
	d.f();
	
	
	cout << "Drill2\n";
	
	dr.vf();
	dr.f();
	
	cout << "Drill3\n";

	d2.f();
	d2.vf();
	d2.pvf();

	f(d21);
	f(d22);

	
	
	
	return 0;
}
