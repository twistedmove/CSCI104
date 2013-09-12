#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct node{
	int value;
	bool checked;
	node* neighbors[2];
};




int traveling(node* array[20]){
	for (int i=0; i<20; i++){
		if(array[i]->checked == false){
			set array[i]->checked = true;
		}
		else if(array[i]->checked == true){ 
			return
		}
	}
}


int main(){
	string fileName;
	int tempNum;
	int tempNodeNum;
	node *tempNode;
	node* array[20];

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

	traveling(array);

	delete[] tempNode;
	tempNode = NULL;
}

