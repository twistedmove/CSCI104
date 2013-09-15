/*
(6) Read a list of strings (one per line) from a file, and output them in the opposite order. 
	Your file should not contain a first line telling you how many strings there are, but just have one string per line. 
	The output should then first print the string from the last line, then the second-last, etc., 
		...until you finally output the string on the first line.
	You should solve this by outputting the elements of a singly linked list in reverse order
		For doing that, write a recursive function. (This is by far the easiest way to do it.)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct Node{
	string word;		// string word
	Node *next;			// pointer to the next node
};

void addString(string importWord, Node **head, Node **tail){
	Node *lastNode = new Node;

	lastNode->word = importWord;
	lastNode->next = NULL;

	if ((*head) == NULL){
		(*head) = (*tail) = lastNode;
	}
	else { 
		(*tail)->next = lastNode;
		(*tail) = lastNode; 
	}
}

void printBackwards(Node *currentNode){
	if (currentNode == NULL){
		return;
	} else{
		printBackwards(currentNode->next);
		cout << currentNode->word << endl;
	}
}

int main(){
	string fileName;
	string tempWord;
	int num;
	Node *head = NULL;
	Node *tail = NULL;
	Node *currentNode;

	cout << "Please type 'words.txt' to import." << endl;
	cin >> fileName;
	ifstream importFile(fileName.c_str());
	if (importFile.good()){
		while (importFile.good()){
			importFile >> tempWord;
			addString(tempWord, &head, &tail);
		}	
	}
	else if(importFile.fail()){
		cout << "Error: Check file name and location." << endl;
		return 0;
	}
	importFile.close();

	printBackwards(head);

	return 0;
}