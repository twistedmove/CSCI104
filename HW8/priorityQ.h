#ifndef PRIORITYQ_H_
#define PRIORITYQ_H_

#include "arraydouble.h"
#include <string>


template <typename T>
class Heap{
	public:
		Heap(int d, bool maxHeap);
		~Heap();

		void add(const T& item, bool(*POINTER)(WallPost*, WallPost*));
		void remove(bool(*POINTER)(WallPost*, WallPost*));
		T peek();

		void printHeap() const;


	private:

		bool _isMax;
		int _size;
		int _d;

		void swap(int A, int B);
		void trickleUp(int,bool(*POINTER)(WallPost*, WallPost*));
		void trickleDown(int,bool(*POINTER)(WallPost*, WallPost*));

		int findLargestChildIndex(T[], int, int, bool(*POINTER)(WallPost*, WallPost*));	//child array, size of the child array, index of the first child
		int findSmallestChildIndex(T[], int, int, bool(*POINTER)(WallPost*, WallPost*));

		bool checkifLeaf(int);

		ArrayList<T> *_item;
};

#include "priorityQ.hpp"

#endif
