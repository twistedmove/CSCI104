/*
 * LINKLIST.h
 *
 *  Created on: Sep 20, 2013
 *      Author: BryanChong
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <cstdlib>
#include <iostream>
#include <stdexcept>

template <typename T>
class UserElement{
	public:
		T item;
		UserElement<T> *next;
//		UserElement<T> *previous;
};

template <typename T>
class Iterator;

// LinkedList template of typename T
template <typename T>
class LinkedList{
	public:
		LinkedList();					// constructor
		~LinkedList();					// destructor
		void push_back(T& newElement);	// add element to back of LinkedList
		void deleteList();				// delete linked list

		void SetIteratorBegin();		// hack iterator: sets iterator to 0
		void IncrementIterator();		// hack iterator: increments iterator value
		T& IteratorValue();				// hack iterator: returns value

		void removeObject(T& todelete);	// remove() function
		int size();						// returns _size
		T& returnHead();				// return value of head
		bool isEmpty();					// checks if list is empty
		T& find(int pos);				// finds the item at given position
		void decSize();					// decrements _size

		Iterator<T> begin();			// iterator starts at _head
		Iterator<T> end();				// iterator ends at _tail == NULL

	 // void pop_back();				// remove element from back of  LinkedList
	 // void find(T lookforitem);		// NOT IMPLEMENTED

	private:
		UserElement<T> *_head;			// _head pointer
		UserElement<T> *_tail;			// _tail pointer
		int _size;				// _size of LinkedList
		UserElement<T>* iterator;
};

template <typename T>
class Iterator{
	public:
		Iterator(const LinkedList<T> *bag, UserElement<T> *p);
		T & operator*() const;
		Iterator<T> operator++();
		bool operator==(const Iterator &bagIterator);
		bool operator!=(const Iterator &bagIterator);

	private:
		UserElement<T> *current;
		const LinkedList<T> *traversingItem;
};



/******************************/
/*  NEW ITERATOR CODE BEGINS  */
/******************************/

template <typename T>
Iterator<T>::Iterator(const LinkedList<T> *list, UserElement<T> *p){
	traversingItem = list;
	current = p;
}

template <typename T>
T & Iterator<T>::operator* () const{
	return current->item;
}

template <typename T>
Iterator<T> Iterator<T>::operator++ (){
	current = current->next;
	return *this;
}

template <typename T>
bool Iterator<T>::operator== (const Iterator &listIterator)
{
	return (current == listIterator.current && traversingItem == listIterator.traversingItem);
}

template <typename T>
bool Iterator<T>::operator!= (const Iterator &listIterator)
{
	return (!this->operator== (listIterator));
}

template <typename T>
T& LinkedList<T>::find(int pos){
	int counter = 0;
	UserElement<T>* current = _head;
	if (pos >= _size){
		throw std::invalid_argument("Position is out of bounds.");
	}
	else{
		while (counter < pos){
			current = current->next;
			counter++;
		}
		return current->item;
	}
}

template <typename T>
Iterator<T> LinkedList<T>::begin()
{
	return Iterator<T> (this, _head);
}

template <typename T>
Iterator<T> LinkedList<T>::end()
{
	return Iterator<T> (this, NULL);
}


/****************************/
/*  LINKEDLIST CODE BEGINS  */
/****************************/

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
	//	std::cout << "0" << std::endl;
		UserElement<T> *temp = _head->next;
	//	std::cout << "1" << std::endl;
		delete _head;
		_head = NULL;
	//	std::cout << "2" << std::endl;
		_head = temp;
	//	std::cout << "3" << std::endl;
	}
}


// push_back the LinkedList
template <typename T>
void LinkedList<T>::push_back(T& newElement){
	UserElement<T>* newUser = new UserElement<T>;
	newUser->next = NULL;				// precautionary to initialize
	newUser->item = newElement;			// put newElement into item slot
	if (_size == 0){
		_head = newUser;
		_tail = newUser;
//		_head->previous = NULL;
//		_tail->previous = NULL;
	}
	else {
		_tail->next = newUser;
//		_tail->next->previous = _tail;
		_tail = newUser;
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
T& LinkedList<T>::returnHead(){
	return _head->item;
}

template <typename T>
void LinkedList<T>::decSize(){
	_size--;
}

template <typename T>
int LinkedList<T>::size(){
	return _size;
}


template <typename T>
void LinkedList<T>::removeObject(T& todelete){
	UserElement<T> * tempPrev = NULL;
	UserElement<T> * tempCurrent = _head;
	if (&todelete == &(_head->item)){
		_head = _head->next;
		delete tempCurrent;
		_size--;
		return;
	}
	while (&todelete != &(tempCurrent->item)){
		tempPrev = tempCurrent;
		tempCurrent = tempCurrent->next;
	}
	if (&todelete == &(_tail->item)){
		delete _tail;
		_tail = tempPrev;
		tempPrev->next = NULL;
	}
	if (tempPrev != NULL){
		tempPrev->next = tempCurrent->next;
		delete tempCurrent;
	}
	else{
		_head = tempCurrent->next;
		delete tempCurrent;
	}
	_size--;
}

template <typename T>
bool LinkedList<T>::isEmpty(){
	if (_size == 0)
		return true;
	else
		return false;
}




/***********************************/
/*  PREVIOUS ITERATOR CODE BEGINS  */
/***********************************/

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




#endif /* LINKLIST_H_ */
