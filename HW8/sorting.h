/*
 * sorting.h
 *
 *  Created on: Nov 13, 2013
 *      Author: Kempe
 *  	Modified: Bryan
 */

#ifndef SORTING_H_
#define SORTING_H_

#include "wallpost.h"
#include "mergesort.h"
#include <vector>
#include <iostream>
#include <cstdlib>


// asking for a lot.. especially using comparitors.
// partial credit for something?
bool (*mSort)(WallPost*, WallPost*);

bool Comparitor(WallPost* A, WallPost* B){
	if (A->timeComparison() >= A->timeComparison()){
		return true;
	}
	else{
		return false;
	}
}

std::vector<WallPost*, std::vector<WallPost*>, mSort> p(Comparitor);




#endif /* SORTING_H_ */
