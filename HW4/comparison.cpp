#include "linkedlist.h"
#include "arraylist.h"
#include "arraydouble.h"
#include "arrayten.h"
#include "arrayone.h"
#include <iostream>
#include <ctime>
using namespace std;

int main(){

//	int num;
//	int pos;
	int zero = 0;
	int one = 1;
	int two = 2;
//	int three = 3;


	// LinkedList
//	int size = 0;

	LinkedList<int> *newList = new LinkedList<int>;
	newList->push_back(zero);
	newList->push_back(one);
	newList->push_back(two);

	for (int i = 0; i < 3; i++){
		cout << newList->get(i) << endl;
	}

/*
	clock_t timeStart;
	clock_t timeEnd;
	timeStart = clock();

	for (int i=0; i<2000 ;i++){
		size = newList->getsize();
		newList->insert(size/2,i);
	}

	timeEnd = clock();
	cout << (double)(timeEnd - timeStart)/CLOCKS_PER_SEC << endl;
*/

/*
	cout << newList->get(zero) << endl;
	cout << newList->get(one) << endl;
	cout << newList->get(two) << endl;
	cout << newList->get(three) << endl;
	cout << newList->get(four) << endl;
	cout << newList->get(five) << endl;

	cout << endl;
	cout <<endl;

	newList->remove(one);
	cout << newList->get(zero) << endl;
	cout << newList->get(one) << endl;
	cout << newList->get(two) << endl;
	cout << newList->get(three) << endl;
	cout << newList->get(four) << endl;

	try {
		cout << newList->get(five) << endl;
	} catch (std::invalid_argument& e) {
		cout << e.what() << endl;
	}
*/

/*
	// ArrayList
	ArrayTen<int> *newarray = new ArrayTen<int>;
	int size;

	newarray->push_back(zero);
	cout << "Size is: " << newarray->getsize() << " Number stored is: " << newarray->get(0) << endl;

	clock_t timeStart;
	clock_t timeEnd;
	timeStart = clock();

	for (int i=0; i<2000; i++){
		size = newarray->getsize();
		newarray->insert(size/2,i+1);
		cout << "Size is: " << newarray->getsize() << " Array number is: " << newarray->get(i) << endl;
	}

	timeEnd = clock();
	cout << (double)(timeEnd - timeStart)/CLOCKS_PER_SEC << endl;

*/
}
