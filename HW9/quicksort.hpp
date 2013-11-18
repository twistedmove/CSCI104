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
void printArray(T a[], int left, int right, int middle){
	for(int i = 0; i<= right; i++){
		std::cout << a[i];
	}
}

template <typename T>
int qSort<T>::partition(T array[], int left, int right) {

	T pivot = array[right];	//select a random pivot to start
    int leftindex = left;

    for (int i = left; i<right; i++){
        if(array[i] <= pivot) {
        	swap(array, leftindex, i);
		    leftindex++;
        }
	}

    swap(array, leftindex, right);
    return leftindex;
}

template <typename T>
void qSort<T>::quickSort(T array[], int left, int right) {
	if (left < right){
	    int middle = partition(array, left, right);
	    quickSort(array, left, middle-1);
	    quickSort(array, middle+1, right);
	    printArray(array, left, right, middle);
	}
}


template <typename T>
void qSort<T>::swap (T a[], int i, int j){
	T b = a[i];
	a[i] = a[j];
	a[j] = b;
}



#endif /* QUICKSORT_HPP_ */
