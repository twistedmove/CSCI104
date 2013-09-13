#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

struct node{
	int value;
	bool checked;
	node* neighbors[2];
};

int counter = 0;

int traveling(node* array[20], int minEnergy, int currentEnergy, int currentNode, int depthCounter){
	array[currentNode-1]->checked = true;
	// Base case
	if (depthCounter == 20){
		if (currentEnergy < minEnergy){
			minEnergy = currentEnergy;
		}
		counter++;
		array[currentNode-1]->checked = false;
		return minEnergy;
	}
	if(array[currentNode-1]->neighbors[0]->checked == false){
		currentEnergy += abs(array[currentNode-1]->value - array[currentNode-1]->neighbors[0]->value);
		minEnergy = traveling(array, minEnergy, currentEnergy, array[currentNode-1]->neighbors[0]->value, depthCounter+1);
		currentEnergy -= abs(array[currentNode-1]->value - array[currentNode-1]->neighbors[0]->value);
	}
	if(array[currentNode-1]->neighbors[1]->checked == false){
		currentEnergy += abs(array[currentNode-1]->value - array[currentNode-1]->neighbors[1]->value);
		minEnergy = traveling(array, minEnergy, currentEnergy, array[currentNode-1]->neighbors[1]->value, depthCounter+1);
		currentEnergy -= abs(array[currentNode-1]->value - array[currentNode-1]->neighbors[1]->value);
	}
	if(array[currentNode-1]->neighbors[2]->checked == false){
		currentEnergy += abs(array[currentNode-1]->value - array[currentNode-1]->neighbors[2]->value);
		minEnergy = traveling(array, minEnergy, currentEnergy, array[currentNode-1]->neighbors[2]->value, depthCounter+1);
		currentEnergy -= abs(array[currentNode-1]->value - array[currentNode-1]->neighbors[2]->value);
	}


/*	
	for (int i=0; i<3; i++){
		if(array[currentNode-1]->neighbors[i]->checked == false){
			currentEnergy += abs(array[currentNode-1]->value - array[currentNode-1]->neighbors[i]->value);
			minEnergy = traveling(array, minEnergy, currentEnergy, array[currentNode-1]->neighbors[i]->value, depthCounter+1);
			currentEnergy -= abs(array[currentNode-1]->value - array[currentNode-1]->neighbors[i]->value);
		}
	}
*/
	array[currentNode-1]->checked = false;
	return minEnergy;
}


int main(){
	string fileName;
	int tempNum;
	int tempNodeNum;
	node *tempNode;
	node* array[20];
	//int energyCons; 		// Energy consumed
	int minEnergy = 99999;		// Counter		
	int currentEnergy = 0;	
	int currentNode = 1;
	int depthCounter = 1;
	int finalEnergy = 0;

// This is initializing dynamically 20 node structs
	for (int i=0; i<20; i++){
			tempNode = new node();
			tempNode->value = i+1;
			tempNode->checked = false;
			array[i] = tempNode;
	}


// Importing from the text file the neighbors
	cout << "Please type 'd20.txt' to import." << endl;
	cin >> fileName;
	ifstream importFile(fileName.c_str());
	if (importFile.good()){
		while (importFile.good()){
			importFile >> tempNum;
			if(importFile.eof()){
				break;
			}
			for (int i=0; i<3; i++){
				importFile >> tempNodeNum;
				array[tempNum-1]->neighbors[i] = array[tempNodeNum-1];
			}
		}	
	}
	else if(importFile.fail()){
		cout << "Error: Check file name and location." << endl;
		return 0;
	}
	importFile.close();

/* Just a loop check if array is exported correctly
	for (int i=0 ; i<20; i++){
		cout << i << " ";
		cout << array[i]->value << " ";
		cout << array[i]->checked << " ";
		cout << array[i]->neighbors[0]->value << " ";
		cout << array[i]->neighbors[1]->value << " ";
		cout << array[i]->neighbors[2]->value << " ";
		cout << endl;
	}	
*/

	finalEnergy = traveling(array, minEnergy, currentEnergy, currentNode, depthCounter);
	cout << "Final energy is: " << finalEnergy << endl;
	cout << "Iterations: " << counter << endl;


	delete[] tempNode;
	tempNode = NULL;
}

