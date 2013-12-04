/*
 * mergesort.h
 *
 *  Created on: Nov 13, 2013
 *      Author: Bryan Chong
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <functional>
#include <vector>


template <typename T>
class mSort{
	public:
		mSort();
		~mSort();
		void swap(std::vector<T>, int, int, bool(*POINTER)(T, T));
		void merge(std::vector<T>, int, int, int, bool(*POINTER)(T, T));
		void mergeSort(std::vector<T>, int, int, bool(*POINTER)(T, T));
	private:

};

#include "mergesort.hpp"



#endif /* MERGESORT_H_ */
