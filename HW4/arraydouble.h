/*
 * arraydouble.h
 *
 *  Created on: Sep 29, 2013
 *      Author: BryanChong
 */

#ifndef ARRAYDOUBLE_H_
#define ARRAYDOUBLE_H_


template <typename T>
class ArrayDouble:public ArrayList<T>{
	public:
		ArrayDouble(int size);
		~ArrayDouble();
	protected:
		void expandArray();

};

template <typename T>
ArrayDouble<T>::ArrayDouble(int size = 10):ArrayList<T>(size){}

template <typename T>
ArrayDouble<T>::~ArrayDouble(){}

template <typename T>
void ArrayDouble<T>::expandArray(){
	T *newarray = new T[ArrayList<T>::_capacity *= 2];
	for (int i = 0; i<ArrayList<T>::_size; i++){
		newarray[i] = ArrayList<T>::array[i];
	}
	ArrayList<T>::array = newarray;
	delete newarray;
}




#endif /* ARRAYDOUBLE_H_ */
