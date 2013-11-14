/*
 * mergesort.h
 *
 *  Created on: Nov 13, 2013
 *      Author: BryanChong
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

class mSort{
	public:
		void swap(int [], int, int);
		void merge(int [], int, int, int);
		void mergeSort(int [], int, int);
		int partition (int [], int, int);
	private:

};


void mSort::swap (int a[], int b, int c)
{
	int temp = a[b];
	a[b] = a[c];
	a[c] = temp;
}

void mSort::merge (int a[], int l, int r, int m)
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

void mSort::mergeSort (int a[], int l, int r){
	if (l < r){
		int m = (l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,r,m);
	}
}

int mSort::partition (int a[], int l, int r)
{
	int i = l;
	int p = a[r];


	for (int j = l; j < r; j ++)
	{
		if (a[j] <= p)
		{ swap (a, i, j); i ++; }
	}
	swap (a, i, r);
	return i;
}



#endif /* MERGESORT_H_ */
