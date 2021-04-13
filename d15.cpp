#include "std_lib_facilities.h"

struct Person {

bool agecheck(string str){

	regex regx("[@!_#$%^&*()<>?/|}{~:]");

	return regex_search(str,regx)==0;
	
}



public:
	Person(){}
	Person(string vnev,string knev,int ev){
		if (ev < 150 && ev > 0 && agecheck(vnev) && agecheck(knev)){
			f_name=vnev;
			l_name=knev; 
			age= ev;} else
			error("Nem jo a beolvasott adat");
	}

	int get_ev() const {return age;}
	string get_v_nev() const {return f_name;}
	string get_k_nev() const {return l_name;}
	string get_full_nev() const {return f_name + "	" + l_name;}

	void set_ev(int eves) {age = eves;}
	void set_v_nev(string neve){f_name = neve;}
	void set_k_nev(string neve){l_name = neve;}


private:
	string f_name;
	string l_name;
	int age;

};




int main () {

Person papa;
Person david;
Person stefi {"Stefike","Imre",20};

string nev;
int ev;

/*papa.set_nev("Goofy");
papa.set_ev(63);

cout << papa.get_nev()<< "     " << papa.get_ev() << endl;*/


/* << "Adj meg egy nevet:\n" ;
cin >> nev;
cout << "Adj meg egy evszamot:\n" ;
cin >> ev;

david.set_nev(nev);
david.set_ev(ev);

cout << david.get_nev()<< "     " << david.get_ev() << endl;*/

cout << stefi.get_k_nev() << endl;
cout << stefi.get_v_nev() << endl;


cout << stefi.get_full_nev()<< "     " << stefi.get_ev() << endl;




return 0;
}