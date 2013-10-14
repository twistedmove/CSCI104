/*
 * calculator.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: BryanChong
 */


#include <iostream>
#include "stack.h"
#include "arraylist.h"
#include "vector.h"
#include "item.h"
using namespace std;


int main(){


	mathVector *vector1 = new mathVector("[1.1,2.2,3.3]");
	mathVector *vector2 = new mathVector(*vector1);
	mathVector *vector3 = new mathVector(111.2);
	mathVector *vector6 = new mathVector("[9.9,8.8,7.7]");
	mathVector *vector5 = new mathVector(1);				//default constructor is normally size 3


	Stack<Item> *itemQ = new Stack<Item>;


//	cout << vector6->getSize() << endl;
//	cout << vector1->getSize() << endl;

	cout << vector1->toString() << endl;

	cout << vector2->toString() << endl;

	mathVector vector4 = *vector1 + *vector2;

	cout << vector3->toString() << endl;

	cout << vector4.toString() << endl;

	cout << (*vector1 == *vector2) << endl;

	// multiply 3 and 3
	*vector5 = (*vector1 * *vector6);

	cout << vector5->toString() << endl;

//	cout << (*vector1 == *vector3) << endl;

//	cout << (*vector1 - *vector2) << endl;


//	for (int i = 0; i < 3 ; i++){
//		cout << (*vector1)[i] << endl;
//	}




	return 0;
}
