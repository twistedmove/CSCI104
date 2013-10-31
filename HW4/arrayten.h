/*
 * arrayten.h
 *
 *  Created on: Sep 29, 2013
 *      Author: BryanChong
 */

#ifndef ARRAYTEN_H_
#define ARRAYTEN_H_

#include <cmath>

template <typename T>
class ArrayTen:public ArrayList<T>{
	public:
		ArrayTen(int size);
		~ArrayTen();
	protected:
		void expandArray();
};

template <typename T>
ArrayTen<T>::ArrayTen(int size = 10):ArrayList<T>(size){}

template <typename T>
ArrayTen<T>::~ArrayTen(){}

template <typename T>
void ArrayTen<T>::expandArray(){
	float temp = ArrayList<T>::_capacity * 1.1;
	ArrayList<T>::_capacity = (int)temp;
	T *newarray = new T[ArrayList<T>::_capacity];

	for (int i = 0; i<ArrayList<T>::_size; i++){
		newarray[i] = ArrayList<T>::array[i];
	}
	ArrayList<T>::array = newarray;
	delete newarray;
}


#endif /* ARRAYTEN_H_ */
