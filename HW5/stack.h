/*
 * stack.h
 *
 *  Created on: Oct 9, 2013
 *      Author: BryanChong
 */

#ifndef STACK_H_
#define STACK_H_

#include "linkedlist.h"
#include <stdexcept>

template <typename T>
class Stack : public LinkedList<T>{
  public:
  	 Stack();
  	~Stack();
  	int size() const;
  	void push(const T&);
  	void pop();
  	bool isEmpty() const;
  	T& top();

  private:

};

template <typename T>
Stack<T>::Stack() : LinkedList<T>(){}

template <typename T>
Stack<T>::~Stack(){
	//this->clear();
}

template <typename T>
int Stack<T>::size() const {
	return this->_size;
}

template <typename T>
void Stack<T>::push(const T& element){
	this->push_back(element);
}


template <typename T>
void Stack<T>::pop (){
	LinkedList<T>::remove(this->_size-1);

	/*
	if (this->_size > 0){
		if (this->_size == 1){
			delete this->_head;
			this->_head = NULL;
			this->_tail = NULL;
		}
		else{
			element<T>* previous_tail = this->_head;

			for (int i=0; i<this->_size-2; i++){
				previous_tail = previous_tail->next;
			}

			delete this->_tail;
			this->_tail = previous_tail;
			this->_tail->next = NULL;
		}
		this->_size --;
	}

	else{
		throw std::invalid_argument ("Head is NULL.");
	}
	*/
}


template <typename T>
T& Stack<T>:: top(){
	return LinkedList<T>::get(this->_size-1);

	/*
	if (this->_size <= 0){
		throw std::invalid_argument("Stack size is 0.");
	}

	else return this->_tail->item;
	*/
}

template <typename T>
bool Stack<T>::isEmpty() const {
	if (this->_size == 0){
		return true;
	}
	else {
		return false;
	}
}

#endif /* STACK_H_ */
