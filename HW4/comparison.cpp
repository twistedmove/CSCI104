#include "linkedlist.h"
#include "arraylist.h"
#include "arraydouble.h"
#include "arrayten.h"
#include "arrayone.h"
#include <iostream>
using namespace std;

int main(){

	int num;
	int pos;
	int zero = 0;
	int one = 1;
	int two = 2;
	int three = 3;
/*

	// LinkedList
	int four = 4;
	int five = 5;

	LinkedList<int> *newList = new LinkedList<int>;
	newList->push_back(one);
	newList->push_back(two);
	newList->push_back(three);
	newList->push_back(four);
	newList->push_back(five);

	cout << "Enter number. Should be 9" << endl;
	cin >> num;
	cout << "Enter position. Should be 1" << endl;
	cin >> pos;

	cout << endl;
	cout << endl;

	newList->insert(one,num);

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

	// ArrayList
	ArrayDouble<int> *newarray = new ArrayDouble<int>;
	newarray->push_back(one);
	newarray->push_back(two);
	newarray->push_back(three);

	cout << "Enter number. Should be 9" << endl;
	cin >> num;
	cout << "Enter position. Should be 1" << endl;
	cin >> pos;

	cout << endl;
	cout << endl;


	newarray->insert(one, num);

	cout << newarray->get(zero) << endl;
	cout << newarray->get(one) << endl;
	cout << newarray->get(two) << endl;
	cout << newarray->get(three) << endl;

	cout << endl;
	cout << endl;

	newarray->remove(one);
	cout << newarray->get(zero) << endl;
	cout << newarray->get(one) << endl;
	cout << newarray->get(two) << endl;

	cout << endl;
	cout << "DONE" << endl;
}
