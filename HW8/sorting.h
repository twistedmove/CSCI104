/*
 * sorting.h
 *
 *  Created on: Nov 13, 2013
 *  	Author: Bryan
 */

#ifndef SORTING_H_
#define SORTING_H_

#include "wallpost.h"
#include "mergesort.h"
#include <functional>
#include <vector>
#include <iostream>
#include <cstdlib>


//this is the right syntax for the function pointer.
//so if you want mSort to be a pointer that points to the function comapritor, you do:

// mSort = Comparator;
//and now that mSort points to a function, you can pass it into other functions

bool (*mSort)(WallPost*, WallPost*);

bool Comparitor(WallPost* A, WallPost* B){
	if (A->timeComparison() >= A->timeComparison()){
		return true;
	}
	else{
		return false;
	}
}



#endif /* SORTING_H_ */
