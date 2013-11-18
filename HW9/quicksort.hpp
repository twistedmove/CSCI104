/*
 * quicksort.hpp
 *
 *  Created on: Nov 15, 2013
 *      Author: BryanChong
 */

#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <iostream>
#include <cstdlib>
#include "quicksort.h"
#include <iostream>
#include <ctime>
#include <vector>


template <typename T>
int qSort<T>::partition(T array[], int left, int right) {

	T pivot = array[right];
    int i = left;

    for (int j = left; j < right; j++){
        if(array[i] <= pivot) {
        	swap(array, i, j);
		    i++;
        }
	}
    swap(array, i, right);
    return i;
}

template <typename T>
void qSort<T>::quickSort(T array[], int left, int right) {
	if (left < right){
	    int middle = partition(array, left, right);
	    quickSort(array, left, middle-1);
	    quickSort(array, middle+1, right);
	}
}


template <typename T>
void qSort<T>::swap (T a[], int i, int j){
	T b = a[i];
	a[i] = a[j];
	a[j] = b;
}

template <typename T>
void qSort<T>::printArray(T *a, int left, int right, int middle){
	for (int i = 0; i < left; i ++)
		std::cout << "   ";
		for (int i = left; i <= right; i ++){
			std::cout << a[i];
			if (i == middle || i == middle-1){
				std::cout << "|";
			}
			else{
				std::cout << " ";
			}
	}
	std::cout << std::endl;
}


#endif /* QUICKSORT_HPP_ */
