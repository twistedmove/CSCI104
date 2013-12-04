/*
 * arraydouble.h
 *
 *  Created on: Sep 29, 2013
 *      Author: BryanChong
 */

#ifndef ARRAYDOUBLE_H_
#define ARRAYDOUBLE_H_

#include <iostream>
#include <cstdlib>

template <typename T>
class ArrayList {
	public:
		ArrayList(int size);
		ArrayList();
		~ArrayList();
		void insert (int pos, const T & item);
		/*  Inserts the item right before position pos, growing the list by 1.
		 *  pos must be between 0 and the current length of the list.
		 *  (The textbook returns a bool - feel free to do that.)
		 */
		void remove (int pos);
		/*  Removes the element at position pos, shrinking the list by 1.
		    pos must be between 0 and the current length of the list minus 1.
		 */
		void set (int pos, const T & item);
		/*  overwrites position pos in the list with item.
		 *  Does not change the length of the list.
		 *  pos must be between 0 and the current length of the list minus 1.
		 */
		T const & get (int pos) const;
		/*  returns the item at position pos, not changing the list.
		 *  pos must be between 0 and the current length of the list minus 1.
		 */
		void clear ();
		void expandArray();
		void push_back(const T & item);
		int size();

	protected:
		T* array;
		int _size;
		int _capacity;

};


template <typename T>
ArrayList<T>::ArrayList(int _capacity){
	this->_capacity = _capacity;	// size of the array
	this->_size = 0;			//elements in the array
	array = new T[_capacity];
}

template <typename T>
ArrayList<T>::ArrayList(){
	this->_capacity = 10;	// size of the array
	this->_size = 0;			//elements in the array
	array = new T[_capacity];
}


template <typename T>
ArrayList<T>::~ArrayList(){
	delete [] array;
}


template <typename T>
int ArrayList<T>::size(){
	return _size;
}


template <typename T>
void ArrayList<T>::push_back(const T & item){
	if (_size == _capacity){
			expandArray();
	}
	if (_size == 0){
		array[0] = item;
		_size++;
	}
	else{
		array[_size] = item;
		_size++;
	}
}


template <typename T>
void ArrayList<T>::set(int pos, const T & item){
	array[pos] = item;
}


template <typename T>
T const & ArrayList<T>::get(int pos) const{
	return array[pos];
}


template <typename T>
void ArrayList<T>::insert(int pos, const T & item){
	if (pos > _size - 1 || pos < 0){
		std::cout << "Position value out of bounds." << std::endl;
		return;
	}
	// if the array is full
	if (_size == _capacity-1){
		expandArray();
	}
	//std::cout << _size << " and " << _capacity << std::endl;
	// not full
	for (int i=_size-1; i >= pos ;i--){
			array[i+1] = array[i];
	}
	array[pos] = item;
	_size++;
}


template <typename T>
void ArrayList<T>::remove(int pos){
	if (pos > _size - 1 || pos < 0){
		std::cout << "Position value out of bounds." << std::endl;
		return;
	}

	T *newArray = new T[_size];
	for (int i = 0; i < pos; i++){
		newArray[i] = array[i];
	}
	for (int i = pos; i < _size-1; i++){
		newArray[i] = array[i+1];
	}
	delete [] array;
	array = newArray;
	_size--;
}


template <typename T>
void ArrayList<T>::clear(){
	for (int i = 0; i<_size-1; i++){
		array[i] = NULL;
	}
	delete [] array;
}

template <typename T>
void ArrayList<T>::expandArray(){
		T *newarray = new T[_capacity *= 2];
	for (int i = 0; i < _size; i++){
		newarray[i] = array[i];
	}
		array = newarray;
		delete [] newarray;
}


#endif /* ARRAYDOUBLE_H_ */
