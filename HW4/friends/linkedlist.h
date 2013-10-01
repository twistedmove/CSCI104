/*
 * linkedlist.h
 *
 *  Created on: Sep 29, 2013
 *      Author: BryanChong
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <cstdlib>
#include <iostream>
#include <stdexcept>

template <class T>
struct element {
	T item;
	element<T> *next;
};

template <class T>
class LinkedList {
	public:
		LinkedList();
		~LinkedList();
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
		void push_back(T & item);
		int getsize();

	private:
		int _size;
		element<T> *_head;
		element<T> *_tail;
		element<T> *_iterator;

};

template <typename T>
int LinkedList<T>::getsize(){
	return _size;
}


template <typename T>
LinkedList<T>::LinkedList(){
	_size = 0;
	_head = 0;
	_tail = 0;
	_iterator = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	clear();
}

template <typename T>
void LinkedList<T>::set(int pos, const T & newitem){
	if (pos > _size){
		std::cout << "Position out of bounds." << std::endl;
	}
	else{
		element<T> *temphead = _head;
		for(int i=0; i<pos; i++){
			temphead = temphead->next;
		}
		temphead->item = newitem;
	}
}


template <typename T>
T const & LinkedList<T>::get(int pos) const{
	if (pos > _size-1 || pos < 0){
		throw std::invalid_argument("Index out of bounds.");
	}
	else{
		element<T> * temphead = _head;
		for(int i=0; i<pos; i++){
			temphead = temphead->next;
		}
		return temphead->item;
	}
}


template <typename T>
void LinkedList<T>::insert(int pos, const T & item){
	element<T> * tempPrev = NULL;
	element<T> * tempCurrent = _head;

	if (pos > _size || pos < 0){
		return;
	}
/*	else if (_size == 0){
		element<T> * newItem = new element<T>;
		newItem->next = NULL;
		_head = newItem;
		_tail = newItem;
	}
*/	// only one element
	else{
		element<T> * insertItem = new element<T>;
		insertItem->item = item;
		for(int i = 0; i < pos; i++){
			tempPrev = tempCurrent;
			tempCurrent = tempCurrent->next;
		}
		tempPrev->next = insertItem;
		insertItem->next = tempCurrent;
	}
	_size++;

}

template <typename T>
void LinkedList<T>::remove(int pos){
	element<T> * tempPrev = NULL;
	element<T> * tempCurrent = _head;
	// set all next
	if (pos > _size-1 || pos < 0){
		return;
	}
	for (int i=0; i<pos; i++){
		tempPrev = tempCurrent;
		tempCurrent = tempCurrent->next;
	}
	// i'm on the last node
	if (tempCurrent == _tail){
		tempPrev->next = NULL;
		_tail = tempPrev;
		delete tempCurrent;
	}
	else{
		tempPrev->next = tempCurrent->next;
		delete tempCurrent;
	}
	_size--;
}

template <typename T>
void LinkedList<T>::clear(){
	while (_head != NULL){
		element<T> *temp = _head->next;
		delete _head;
		_head = temp;
	}
}

template <typename T>
void LinkedList<T>::push_back(T & item){
	element<T> *newItem = new element<T>;
	newItem->next = NULL;
	newItem->item = item;
	if (_size == 0){
			_head = newItem;
			_tail = newItem;
	}
	else{
		_tail->next = newItem;
		_tail = newItem;
	}

	_size++;
}



#endif /* LINKEDLIST_H_ */
