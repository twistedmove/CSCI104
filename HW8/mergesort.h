/*
 * mergesort.h
 *
 *  Created on: Nov 13, 2013
 *      Author: Bryan Chong
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <functional>

template <typename T>
class mSort{
	public:
		mSort();
		~mSort();
		void swap(int [], int, int, bool(*POINTER)(T, T));
		void merge(int [], int, int, int, bool(*POINTER)(T, T));
		void mergeSort(int [], int, int, bool(*POINTER)(T, T));
		int partition (int [], int, int, bool(*POINTER)(T, T));
	private:

};



#endif /* MERGESORT_H_ */
