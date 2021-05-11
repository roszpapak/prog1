#include "std_lib_facilities.h"


template<typename T> 
struct S {
private:
	T val;
public:
	S(T vallue = T()) : val(vallue){};
	T& get();
	T get() const {return val;}
	T operator = (const T&);

};

template<typename T> T& S<T>::get() {return val;}

template<typename T> T S<T>::operator=(const T& val2) {val=val2;}

template<typename T> void read_val(T& v){
	cin >> v;}


template<typename T>
istream& operator >> (istream& is, S<T>& tt){
	is >> tt.get();
	return is;
}


int main() {

	S<int> szam {69};
	S<char> betu {'k'};
	S<double> valos {12.34};
	S<string> szoveg = {"Papa"};
	S<vector<int>> vector = {{100,200,300}};


	cout << szam.get() << endl;
	cout << betu.get() << endl;
	cout << valos.get() << endl;

	cout << "Adj meg egy szamot:" << endl;
	read_val(szam);
	cout << "Adj meg egy betut:" << endl;
	read_val(betu);
	cout << "Adj meg egy valos szamot:" << endl;
	read_val(valos);

	cout << szam.get() << endl;
	cout << betu.get() << endl;
	cout << valos.get() << endl;


	return 0;
}