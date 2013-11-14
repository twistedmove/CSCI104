/*
 * mergesort.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: BryanChong
 */

#include "mergesort.h"
#include <functional>

template <typename T>
mSort<T>::mSort(){}

template <typename T>
mSort<T>::~mSort(){}

template <typename T>
void mSort<T>::swap(int a[], int b, int c, bool(*POINTER)(T* x, T* y))
{
	int temp = a[b];
	a[b] = a[c];
	a[c] = temp;
}

template <typename T>
void mSort<T>::merge(int a[], int l, int r, int m, bool(*POINTER)(T* x, T* y))
{
	int temp[r+1-l];
	int i = l;
	int j = m+1;
	int k = 0;

	while (i <= m || j <= r){
		if (i <= m && (j > r || a[i] < a[j])){
			temp[k] = a[i]; i ++; k ++;
		}
		else {
			temp[k] = a[j]; j ++; k ++;
		}
	}
	for (k = 0; k < r+1-l; k ++){
		a[k+l] = temp[k];
	}
}

template <typename T>
void mSort<T>::mergeSort(int a[], int l, int r, bool(*POINTER)(T* x, T* y)){
	if (l < r){
		int m = (l+r)/2;
		mergeSort(a,l,m,bool(*POINTER)(x, y));
		mergeSort(a,m+1,r,bool((*POINTER)(T* x, T* y)));
		merge(a,l,r,m,bool((*POINTER)(T* x, T* y)));
	}
}

template <typename T>
int mSort<T>::partition(int a[], int l, int r, bool(*POINTER)(T* x, T* y))
{
	int i = l;
	int p = a[r];


	for (int j = l; j < r; j ++)
	{
		if (a[j] <= p)
		{ swap (a, i, j, bool((*POINTER)(T* x, T* y))); i ++; }
	}
	swap (a, i, r, bool(*POINTER)(T* x, T* y));
	return i;
}


