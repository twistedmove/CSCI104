/*
 * LINKLIST.h
 *
 *  Created on: Sep 20, 2013
 *      Author: BryanChong
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <cstdlib>

template <typename T>
struct UserElement{
	T item;
	UserElement<T> *next;
	UserElement<T> *previous;
};

// LinkedList template of typename T
template <typename T>
class LinkedList{
	public:
		LinkedList();			// constructor
		~LinkedList();			// destructor
		void push_back(T& newElement);		// add element to back of LinkedList
//		void pop_back();		// remove element from back of  LinkedList
		void find(T lookforitem);
		void deleteList();		// delete linked list
		void SetIteratorBegin();
		void IncrementIterator();
		T& IteratorValue();
		void removeObject(T& todelete);
		int size();				// returns _size
		int returnHead();		// return value of head

	private:
		UserElement<T> *_head;			// _head pointer
		UserElement<T> *_tail;			// _tail pointer
		int _size;				// _size of LinkedList
		UserElement<T>* iterator;
};


// constructor
template <typename T>
LinkedList<T>::LinkedList(){
	_head = NULL;
	_tail = NULL;
    _size = 0;
    iterator = NULL;
};


// destructor
template <typename T>
LinkedList<T>::~LinkedList(){
  deleteList();
}


// delete the LinkedList
template <typename T>
void LinkedList<T>::deleteList(){
	while (_head != NULL){
		UserElement<T> *temp = _head->next;
		delete _head;
		_head = temp;
	}
}


// push_back the LinkedList
template <typename T>
void LinkedList<T>::push_back(T& newElement){
	UserElement<T>* newUser = new UserElement<T>;
	newUser->next = NULL;				// precautionary to initialize
	newUser->item = newElement;			// put newElement into item slot
	if (_size == 0){
		_head = _tail = newUser;
//		_head->previous = NULL;
//		_tail->previous = NULL;
	}
	else {
		_tail->next = newUser;
//		_tail->next->previous = _tail;
		_tail = _tail->next;
	}
	_size++;
}

/*
template <typename T>
void LinkedList<T>::pop_back(){
	UserElement<T>* LastUser = NULL;
	if(_size > 0){
		if(_size == 1){
			delete _head, _tail;
			_head = NULL;
			_tail = NULL;
		}
		else{
			_tail->previous->next = NULL;
			LastUser = _tail->previous;
			delete _tail;
			_tail = LastUser;				// or now the last user
		}
	}
}
*/

template <typename T>
int LinkedList<T>::returnHead(){
	return _head->item;
}

template <typename T>
int LinkedList<T>::size(){
	return _size;
}

//iterator begins at head, the beginning
template <typename T>
void LinkedList<T>::SetIteratorBegin(){
	iterator = _head;
}

// if the next one is not null then iterate to the next "object"
template <typename T>
void LinkedList<T>::IncrementIterator(){
	if (iterator->next != NULL){
		iterator = iterator->next;
	}
}

// return the "item" at the current iterator object
template <typename T>
T& LinkedList<T>::IteratorValue(){
	return iterator->item;
}

template <typename T>
void LinkedList<T>::removeObject(T& todelete){
	UserElement<T> * tempPrev = NULL;
	UserElement<T> * tempCurrent = _head;

	while (&todelete != &(tempCurrent->item)){
		tempPrev = tempCurrent;
		tempCurrent = tempCurrent->next;
	}
	if (tempPrev != NULL){
		tempPrev->next = tempCurrent->next;
		delete tempCurrent;
	}
	else{
		delete tempCurrent;
	}
	_size--;
}

#endif /* LINKLIST_H_ */
