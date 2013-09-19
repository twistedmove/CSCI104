/*
(5) Implement a linked lists of strings. 
	> Your list should start out empty and have a function for adding a new string at the end of the list.
*/

#include <iostream>
#include <string>
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

int main(){
	string tempWord;
	int num;
	int counter = 0;
	Node *head = NULL;
	Node *tail = NULL;
	Node *lastNode;

	cout << "How many words do you want to enter?" << endl;
	cin >> num;
	cout << "Enter your words now." << endl;

	for(int i=0; i<num; i++){
		cin >> tempWord;
		addString(tempWord, &head, &tail);
	}
	cout << endl;
	cout << "Your words are..." << endl;
	for (lastNode = head; lastNode != NULL; lastNode = lastNode->next){
		cout << counter << ": " << lastNode->word << endl;
		counter++;
	}

	return 0;
}