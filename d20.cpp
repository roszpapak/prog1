#include "std_lib_facilities.h"
#include <list>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename C>
void print(const C& c){
	for(auto& a:c)
		cout << a << " " ;
	cout<< endl;

}


template<typename C>
void increase(C& c, int szam=0){

	for(auto& a:c)
		a = a+szam;
}


template<typename Iter1,typename Iter2>
Iter2 copy2(Iter1 f1,Iter1 e1 ,Iter2 f2){

	for(Iter1 i = f1; i != e1; i++)
		*f2++ = *i ;
	
	return f2;
}


int main(){
	
	array<int,10>szam_arr = {1,2,3,4,5,6,7,8,9,10};
	vector<int> szam_vec = {1,2,3,4,5,6,7,8,9,10};
	list <int> szam_lis = {1,2,3,4,5,6,7,8,9,10};

	// NOVELES !!!!!!//

	cout << "Az eredeti szamok:" << endl;
	print(szam_arr);

	increase(szam_arr,2);

	cout << "A novelt array:" << endl;
	print(szam_arr);


	increase(szam_vec,3);

	cout << "A novelt vector:" << endl;
	print(szam_vec);

	increase(szam_lis,5);
	cout << "A novelt lista:" << endl;
	print(szam_lis);

	
	// MASOLAS!!!!!!!//

	vector<int> copy_vector(szam_arr.size());
	copy2(szam_arr.begin(),szam_arr.end(),copy_vector.begin());

	cout << "A masolt array vectroba" << endl;
	print(copy_vector);


	array<int,10>copy_list;
	copy2(szam_lis.begin(),szam_lis.end(),copy_list.begin());

	cout << "A masolt lista arraybe" << endl;
	print(copy_list);


	//FIND!!!!!!!!//




	auto p = find(szam_vec.begin(),szam_vec.end(),3);
	auto q = find(szam_lis.begin(),szam_lis.end(),27);

	if(p != szam_vec.end()){
		cout << "Megtalaltuk :"<< distance(szam_vec.begin(),p) <<". helyen van" << endl;

		if(q != szam_lis.end()){
			cout << "Megtalaltuk :" << distance(szam_lis.begin(),q) << ". helyen van" << endl;
		}

		else cout << "Nincs ilyen elem a listaban" << endl;

	}
	
	else cout << "Nincs ilyen elem a vectorban" << endl;


	return 0;
}