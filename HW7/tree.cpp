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
using namespace std;

int main(){

/* Debug and testing on a binary
	Heap<int> priority(2, true);

	priority.add(10);
	priority.add(8);
	priority.add(7);
	priority.add(4);
	priority.add(3);
	priority.add(5);
	priority.add(2);
	priority.printHeap();
	cout << "removing" << endl;
	priority.remove();
	priority.printHeap();
*/


	int randholder = 0;
	clock_t timeStart;
	clock_t timeEnd;
	int counter = 2;

	for (int j = 0; j<10; j++){
		Heap<int> priority(counter, true);
		timeStart = clock();
		for (int i = 0; i < 10000; i++){
			srand (time(NULL));
			randholder = rand()%100;
			priority.add(randholder);
		}
		timeEnd = clock();
		cout << "Insertion took: " << (double)(timeEnd - timeStart)/CLOCKS_PER_SEC << endl;
		counter += 10;
	}


	for (int j = 0; j < 10; j++){
		Heap<int> test(counter, true);
		for (int i = 0; i < 10000; i++){
			srand (time(NULL));
			randholder = rand()%100;
			test.add(randholder);
		}
		timeStart = clock();
		for (int j = 0; j < 10000; j++){
			test.remove();
		}
		timeEnd = clock();
		cout << "Removal took: " << (double)(timeEnd - timeStart)/CLOCKS_PER_SEC << endl;
		counter += 10;
	}

	return 0;
}



