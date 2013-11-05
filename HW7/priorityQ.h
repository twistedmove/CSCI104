#ifndef PRIORITYQ_H_
#define PRIORITYQ_H_

#include "arraydouble.h"
#include <string>


template <typename T>
class Heap{
	public:
		Heap(int d, bool maxHeap);
		~Heap();

		void add(const T& item);
		void remove();
		T& peek();

		void printHeap() const;


	private:

		bool _isMax;
		int _size;
		int _d;

		void swap(int A, int B);
		void trickleUp(int);
		void trickleDown(int);

		int findLargestChildIndex(T[], int, int);	//child array, size of the child array, index of the first child
		int findSmallestChildIndex(T[], int, int);

		bool checkifLeaf(int);

		ArrayList<T> *_item;
};

#include "priorityQ.hpp"

#endif
