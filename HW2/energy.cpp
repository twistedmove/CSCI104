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


int traveling(node* array[20], int energyCons, int counter, int current, int previous){
	// If all the "neighbors->checked = true" AND "counter < 20" is done;	
	if(array[counter]->checked == false && array[counter]->neighbors[current]->checked == false){
		cout << array[counter]->value << endl;
		cout << "Entered 1" << endl;
		previous = counter;
		array[counter]->checked = true;
		energyCons += abs(array[counter]->value - array[counter]->neighbors[current]->value);
		counter = array[counter]->neighbors[current]->value;
		return traveling(array, energyCons, counter-1, current, previous);
	} 
	if(array[counter]->checked == false && array[counter]->neighbors[current]->checked == true){
		cout << array[counter]->value << endl;
		cout << "Entered 2" << endl;
		previous = counter;
		array[counter]->checked = true;
		if(array[counter]->neighbors[current+1]->checked == false){
			cout << "Entered 3" << endl;
			energyCons += abs(array[counter]->value - array[counter]->neighbors[current+1]->value);
			counter = array[counter]->neighbors[current+1]->value;
			return traveling(array, energyCons, counter-1, current, previous);
		} else if (array[counter]->neighbors[current+2]->checked == false){
			cout << "Entered 3" << endl;
			energyCons += abs(array[counter]->value - array[counter]->neighbors[current+2]->value);
			counter = array[counter]->neighbors[current+2]->value;
			return traveling(array, energyCons, counter-1, current, previous);
		} else{
			cout << "Entered 3" << endl;
			energyCons = energyCons - array[counter]->value;
			counter = array[counter]->neighbors[current]->value;
			return traveling(array, energyCons, previous, current, previous);
		}	
	}
	if(array[counter]->checked == true && array[counter]->neighbors[0]->checked == true && array[counter]->neighbors[1]->checked == true && array[counter]->neighbors[2]->checked == true){
		cout << "Dead End" << endl;
	}
	for (int i=0; i<20; i++){
		if(array[i]->checked == true){
			cout << "Done" << endl;
			cout << energyCons << endl;
			return energyCons;
		}
	}

	// If current is not checked and all neighbors are checked, then +1 the counter and try the next tree

}


int main(){
	string fileName;
	int tempNum;
	int tempNodeNum;
	node *tempNode;
	node* array[20];
	int energyCons; 		// Energy consumed
	int counter = 0;		// Counter		
	int current = 0;	
	int previous = 0;

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
//			cout << tempNum << " ";
			for (int i=0; i<3; i++){
				importFile >> tempNodeNum;
				array[tempNum-1]->neighbors[i] = array[tempNodeNum-1];
//				cout << tempNodeNum << " ";
//				cout << array[tempNum-1].neighbors[i] << endl;
			}
//			cout << endl;	
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

	traveling(array, energyCons, counter, current, previous);

	delete[] tempNode;
	tempNode = NULL;
}

