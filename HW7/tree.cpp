/*
 * tree.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: BryanChong
 */

#include "priorityQ.h"
#include "arraydouble.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


int main(){
	Heap<int> priority(3, true);

	priority.add(10);
	priority.add(8);
	priority.add(7);
	priority.add(4);
	priority.add(3);
	priority.add(5);
	priority.add(2);
	priority.printHeap();
	priority.remove();
	priority.printHeap();


/*
//	int randholder = 0;

	for (int i = 0; i < 10000; i++){
		srand (time(NULL));
		randholder = rand()%100;
	}
*/

	return 0;
}



