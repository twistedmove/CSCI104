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
		void swap(std::vector<T>, int, int);
		int partition(std::vector<T>, int, int, int, int);
		void quickSort(std::vector<T>, int, int, int);


	private:


};

#include "quicksort.hpp"


#endif /* QUICKSORT_H_ */
