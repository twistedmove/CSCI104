#ifndef PRIORITYQ_HPP_
#define PRIORITYQ_HPP_

#include "priorityQ.h"
#include "arraydouble.h"
#include <iostream>
#include <stdexcept>
#include <vector>



template <typename T>
Heap<T>::Heap(int d, bool maxHeap){
	_d = d;
	_isMax = maxHeap;
	_size = 0;
	_item = new ArrayList<T>;
}


template <typename T>
Heap<T>::~Heap(){
	delete [] _item;
}


template <typename T>
void Heap<T>::add(const T& item, bool(*POINTER)(WallPost*, WallPost*)){

	_item->push_back(item);
	//std::cout << "Get item in insertion" << _item->get(_size) << std::endl;
	_size++;
	if(_size != 1){
		trickleUp(_size-1, POINTER);
	}
}


template <typename T>
T Heap<T>::peek(){
	return _item->get(0);
}


template <typename T>
void Heap<T>::remove(bool(*POINTER)(WallPost*, WallPost*)){
	if (_size > 1){
		swap(0,_size-1);
		_item->remove(_size-1);
		trickleDown(0, POINTER);
		_size--;
	}
	else if (_size == 1){
		_item->remove(0);
		_size--;
	}
}

template <typename T>
void Heap<T>::swap(int Aindex, int Bindex){
	T temp = _item->get(Aindex);
	_item->set(Aindex, _item->get(Bindex));
	_item->set(Bindex, temp);
}


template <typename T>
void Heap<T>::trickleUp(int node, bool(*POINTER)(WallPost*, WallPost*)){
	if (node == 0){
		return;
	}
	int parent = ((node-1)/_d);
	if (_isMax == true){
		if (POINTER(_item->get(node), _item->get(parent)) == true){
			swap(node, parent);
		}
		else{
			return;
		}
	}
	else{
		if (POINTER(_item->get(node),_item->get(parent))==false){
			swap(node, parent);
		}
		else{
			return;
		}
	}

	trickleUp(parent, POINTER);
}

// used when removing
template <typename T>
void Heap<T>::trickleDown(int node, bool(*POINTER)(WallPost*, WallPost*)){


	if (checkifLeaf(node) == true){
		return;
	}

	T *childArray = new T[_d];				// temporary array of childArray
	int firstChildIndex = ((_d*node)+1);	// finds the index of the current node's first child
	int childIncrementer = ((_d*node)+1);	// simply a counter starting from current node's first child
	int sizeChildArray = 0;					// size of the child array
	int ChildIndex;

	// finds current node's children and add them to the childArray
	for (int i=0; i<_d-1; i++){
		if (childIncrementer > _size){
			break;
		}
		else{
			childArray[i] = _item->get(childIncrementer++);
			sizeChildArray++;
		}
	}

	if (_isMax == true){
			ChildIndex = findLargestChildIndex(childArray, sizeChildArray, firstChildIndex, POINTER);
			if (_item->get(ChildIndex) != NULL){	//HEREEEEE
				if (POINTER(_item->get(node), _item->get(ChildIndex)) == false){
					swap(node, ChildIndex);
				}
			}
		else{
			return;
		}
	}
	else{
		ChildIndex = findSmallestChildIndex(childArray, sizeChildArray, firstChildIndex, POINTER);
		if (POINTER(_item->get(node), _item->get(ChildIndex)) == true){
			swap(node, ChildIndex);
		}
		else{
			return;
		}
	}

	delete [] childArray;
	childArray = NULL;
	trickleDown(firstChildIndex, POINTER);
}

template <typename T>
int Heap<T>::findLargestChildIndex(T childArray[], int sizeChildArray, int firstChildIndex, bool(*POINTER)(WallPost*, WallPost*)){
	T biggestChild = childArray[0];
	int biggestChildIndex = 0;

	for (int i = 0; i<sizeChildArray; i++){
		if (biggestChild < childArray[i]){
			biggestChild = childArray[i];
			biggestChildIndex = firstChildIndex+i;
		}
		else{
			biggestChildIndex = firstChildIndex;
		}
	}

	return biggestChildIndex;
}

template <typename T>
int Heap<T>::findSmallestChildIndex(T childArray[], int sizeChildArray, int firstChildIndex, bool(*POINTER)(WallPost*, WallPost*)){
	T smallestChild = childArray[0];
	int smallestChildIndex = 0;

	for (int i = 0; i<sizeChildArray; i++){
		if (smallestChild > childArray[i]){
			smallestChild = childArray[i];
			smallestChildIndex = firstChildIndex+i;
		}
	}

	return smallestChildIndex;
}

template <typename T>
void Heap<T>::printHeap() const{
	std::cout << "Heap contents are: " << std::endl;
	for(unsigned int i=0; i < _size; i++){
		std::cout << i << ": " << _item->get(i);
		std::cout << std::endl;
	}
}


template <typename T>
bool Heap<T>::checkifLeaf(int node){
	if (((node*_d)+1) > _size){
		return true;
	}
	return false;
}


#endif /* PRIORITYQ_HPP_ */
