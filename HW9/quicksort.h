/*
 * quicksort.h
 *
 *  Created on: Nov 15, 2013
 *      Author: BryanChong
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <vector>

template <typename T>
class qSort{
	public:
		void swap(T [] , int, int);
		int partition(T [], int, int);
		void quickSort(T [], int, int);
		void printArray(T [], int, int, int);


	private:


};

#include "quicksort.hpp"


#endif /* QUICKSORT_H_ */
