/*
 * mergesort.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: BryanChong
 */

#include "mergesort.h"
#include <functional>
#include <vector>

template <typename T>
mSort<T>::mSort(){}

template <typename T>
mSort<T>::~mSort(){}

template <typename T>
void mSort<T>::swap(std::vector<T> a, int b, int c, bool(*POINTER)(T, T))
{
	T temp = a[b];
	a[b] = a[c];
	a[c] = temp;
}

template <typename T>
void mSort<T>::merge(std::vector<T> a, int l, int r, int m, bool(*POINTER)(T, T))
{
	T temp[r+1-l];
	int i = 0;
	int j = m+1;
	int k = 0;

	while (POINTER(a[i],a[m]) == false || POINTER(a[j],a[r]) == false || a[i] == a[m] || a[j] == a[r]){
		if ((POINTER(a[i],a[m]) == false || a[i] == a[m]) && (POINTER(a[j],a[r]) == true || POINTER(a[i],a[j]) == false)){
			temp[k] = a[i];
			i++;
			k++;
		}
		else {
			temp[k] = a[j];
			j++;
			k++;
		}
	}
	for (int k = 0; k < r+1-l; k++){
		a[k+l] = temp[k];
	}
}

template <typename T>
void mSort<T>::mergeSort(std::vector<T> a, int l, int r, bool(*POINTER)(T, T)){
	std::cout << "fdsa " << r << std::endl;
	if (l < r){
		int m = (l+r)/2;
		mergeSort(a,l,m,POINTER);
		mergeSort(a,m+1,r,POINTER);
		merge(a,l,r,m,POINTER);
	}
}

