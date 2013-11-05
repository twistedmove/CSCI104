/*
 * tree.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: BryanChong
 */

#include "priorityQ.h"
#include "arraydouble.h"
#include "student.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

void menu(){
	cout << "*---------------------------*" << endl;
	cout << "* 1. Add student record     *" << endl;
	cout << "* 2. Remove student record  *" << endl;
	cout << "* 3. Exit                   *" << endl;
	cout << "*---------------------------*" << endl;
}

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


	cout << endl << endl;
	int selection = 0;
//	Heap<Student> queue(2, true);

	cout << "*---------------------------*" << endl;
	cout << "* 1. Add student record     *" << endl;
	cout << "* 2. Remove student record  *" << endl;
	cout << "* 3. Exit                   *" << endl;
	cout << "*---------------------------*" << endl;

	while(selection != 3){
		cout << "Selection: ";
		cin >> selection;

		if (cin.fail()){
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid Selection." << endl;
			continue;
		}
		cin.clear();
		cin.ignore(1024,'\n');
		cout << endl;

		switch (selection)
		{
			case 1:
			{

				char tempName[512];
				string name;
				int tempid;

				cout << "Please enter a new name." << endl;
				cin.ignore();
				cin.getline(tempName,512);
				name = tempName;
				cout << "Please enter your student ID" << endl;
				cin >> tempid;

/* NOT IMPLEMENTED
				Student newstudent(name,tempid);
				queue.add(newstudent);



				Student tempStu = queue.peek();
				string tempn = tempStu.getName();
				int tempi = tempStu.getID();
				cout << "First on list is: " << tempn << endl;
				cout << "Student's ID is: " << tempi << endl;
*/
				menu();
				break;
			}
			case 2:
			{
/* NOT IMPLEMENTED
				queue.remove();

				Student tempStu;
				tempStu = queue.peek();
				string tempn = tempStu.getName();
				int id = tempStu.getID();
				cout << "First on list is: " << tempn << endl;
				cout << "Student's ID is: " << tempi << endl;
*/
				menu();
				break;
			}
			case 3:
			{
				cout << "!--------Program Exited--------!" << endl;
				cout << endl;
				break;
			}
			default:
			{
				cout << "!--------Invalid Choice--------!" << endl;
			}

		} // end of switch
	} // end of while



	return 0;
}



