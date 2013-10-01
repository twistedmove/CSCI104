/*
 * arrayone.h
 *
 *  Created on: Sep 29, 2013
 *      Author: BryanChong
 */

#ifndef ARRAYONE_H_
#define ARRAYONE_H_

#include <iostream>

template <typename T>
class ArrayOne:public ArrayList<T>{
	public:
		ArrayOne(int size);
		~ArrayOne();
	protected:
		void expandArray();
};

template <typename T>
ArrayOne<T>::ArrayOne(int size = 10):ArrayList<T>(size){}

template <typename T>
ArrayOne<T>::~ArrayOne(){}

template <typename T>
void ArrayOne<T>::expandArray(){
	T *newarray = new T[ArrayList<T>::_capacity++];

	for (int i = 0; i<ArrayList<T>::_size; i++){
		newarray[i] = ArrayList<T>::array[i];
	}
	ArrayList<T>::array = newarray;
	delete newarray;
}


#endif /* ARRAYONE_H_ */
