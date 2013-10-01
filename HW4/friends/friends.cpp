#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <cmath>
#include <queue>
#include <deque>
#include "linkedlist.h"
using namespace std;

struct node{
	int value;
	LinkedList<int> *enemies;
};

int guesting(node * nodearray[20], int number){

	int tempvar;
	int score = 0;
	bool inunwanted;
	bool ininvited;
	bool isEnemy = false;
	std::deque<int> *open = new std::deque<int>;
	std::deque<int> *unwanted = new std::deque<int>;
	std::deque<int> *invited = new std::deque<int>;


	for (int i = 0; i<number; i++){
		open->push_back(i);

		while (!open->empty()){
			tempvar = open->front();
			open->pop_front();

			// get the friends
			for (int j = 0; j < number; j++){

				if (nodearray[tempvar]->enemies->get(0) == -1){

					continue;
				}
				for(int k =0; k < nodearray[tempvar]->enemies->getsize(); k++){
					if (nodearray[tempvar]->enemies->get(k) == j){
						isEnemy = true;
					}
				}
				bool isUnwanted = false;
				bool isInvited = false;
				if (isEnemy == false ){
					for(int b = 0; b< unwanted->size(); b++){
						if (unwanted->at(b) == j){
							isUnwanted = true;
							break;
						}
					}
					for (int b =0 ; b< invited->size(); b++){
						if (invited->at(b) == j){
							isInvited = true;
						}
					}
					if (!isUnwanted && !isInvited){
						open->push_back(j);
					}
				}
				else{
					unwanted->push_back(j);
				}
				isEnemy = false;
			}


			for (int j=0; j < unwanted->size(); j++){
				if (tempvar == unwanted->at(j)){
					inunwanted = true;
				}
			}

			for (int j=0; j < invited->size(); j++){
				if (tempvar == invited->at(j)){
					ininvited = true;
				}
			}

			if (!ininvited && !inunwanted){
				invited->push_back(tempvar);
			}

			inunwanted = false;
			ininvited = false;
		}
		//calculate invited score
		int tempscore = 0;
		for (int m=0; m<invited->size(); m++){
			tempscore += nodearray[invited->at(m)]->value;
		}
		if (tempscore > score){
			score = tempscore;
		}

		delete open;
		delete unwanted;
		delete invited;

		open = new std::deque<int>;
		unwanted = new std::deque<int>;
		invited = new std::deque<int>;
	}


	return score;
}


int main(){
	string fileName;
	string temporary;
	int totalnumber;
	int tempvalue;
	node* tempNode;
	node* nodearray[20];
	int *array;
	string *enemies;
	int tempnum;
	int tempenemies;

	for (int i=0; i<20; i++){
		tempNode = new node();
		nodearray[i] = tempNode;
		nodearray[i]->enemies = new LinkedList<int>;
	}

	// Importing from the text file
	cout << "Please type 'input.txt' to import." << endl;
	cin >> fileName;
	ifstream importFile(fileName.c_str());
		if (importFile.good()){
				importFile >> totalnumber;

				array = new int[totalnumber];
				enemies = new string[totalnumber];

				if(importFile.eof()){
					cout << "End of file.";
				}
				for (int i=0; i < totalnumber; i++){
					importFile >> tempvalue;
					array[i] = tempvalue;
				}

				getline(importFile, temporary, '\n');
				stringstream ss(temporary);
				for (int i=0; i < totalnumber; i++){
					getline(importFile, temporary, '\n');
					stringstream ss(temporary);
					ss >> tempnum;
					while (!ss.eof()){
						ss >> tempenemies;
						nodearray[tempnum]->enemies->push_back(tempenemies);
						cout <<  tempenemies << " ";
					}
					cout << endl;
				}
		}


		else if(importFile.fail()){
			cout << "Error: Check file name and location." << endl;
			return 0;
		}

	importFile.close();


	for (int i=0; i<20; i++){
		nodearray[i]->value = array[i];
	}

	cout << "Score is: " << guesting(nodearray,20) << endl;

}

