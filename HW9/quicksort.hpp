/*
 * quicksort.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: BryanChong
 */

#ifndef QUICKSORT_CPP_
#define QUICKSORT_CPP_

#include <iostream>
#include <cstdlib>
#include "quicksort.h"
#include <iostream>
#include <ctime>
#include <vector>

template <typename T>
int qSort<T>::partition(std::vector<T> array, int size, int left, int right, int random) {
	T pivot = array[random];	//select a random pivot to start
    int leftindex = left;

    for (int i = left; i<random; i++){
        if(array[i] <= pivot) {
           swap(array, leftindex, i);
           leftindex++;
        }
    	swap(array, leftindex, random);
	}
    return leftindex;
}

template <typename T>
void qSort<T>::quickSort(std::vector<T> array, int size, int left, int right) {
	if (left < right){
	    srand(time(NULL)); // seeding time
	    int random;
	    random = rand() % size;

	    int middle = partition(array, size, left, right, random);
	    quickSort(array, size, left, middle-1);
	    quickSort(array, size, middle+1, random);
	}
}


template <typename T>
void qSort<T>::swap (std::vector<T> a, int i, int j){
	T b = a[i];
	a[i] = a[j];
	a[j] = b;
}



#endif /* QUICKSORT_CPP_ */
