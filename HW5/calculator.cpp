/*
 * calculator.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: BryanChong
 */

#include <iostream>
#include <sstream>
#include <string>
#include "stack.h"
#include "arraylist.h"
#include "vector.h"
#include "item.h"
using namespace std;

bool checkNumber(char input){
	char array[10] = {'0','1','2','3','4','5','6','7','8','9'};
	for (int i=0; i<10; i++){
		if(array[i] == input){
			return true;
		}
	}
	return false;
}

bool checkOperator(char input){
	char array[3] = {'+','-','*'};
	for (int i=0; i<3; i++){
		if (array[i] == input){
			return true;
		}
	}
	return false;
}

bool stopOperator(char input){
	char array[7] = {'+','-','*','(',')','[',']'};
	for (int i=0; i<3; i++){
		if (array[i] == input){
			return true;
		}
	}
	return false;
}

mathVector calculate(Stack<Item> input){


	Item item1 = input.top();
	if (item1.checkVector()){
		mathVector subitem1 = item1.getVector();
	}
	else{
		char subitem1 = item1.getCharacter();
	}
	input.pop();
	Item item2 = input.top();
	if (item1.checkVector()){
		mathVector subitem2 = item2.getVector();
	}
	else{
		char subitem2 = item2.getCharacter();
	}
	input.pop();
	Item item3 = input.top();
	if (item1.checkVector()){
		mathVector subitem3 = item3.getVector();
	}
	else{
		char subitem3 = item3.getCharacter();
	}
	input.pop();

	mathVector returnVector = subitem3 + subitem2 + subitem1;
	return returnVector;
}

int main(){

	string userInput;
	Stack<Item> itemQ;

	cout << endl;
	cout << "Please enter your calculation." << endl;
	cout << "     > Please include [ ] and exclude spaces." << endl;
	cout << "	  > Format: (([1,1]+[-1,-1])*([2,3]+[3,4]))" << endl;
	cout << "     > Format: ([1.1,2.2,3.3]*[1.1,2.2,3.3])" << endl;
	cout << "     > Format: (1+(2+3))" << endl;
	cin >> userInput;

	int size = userInput.length();


	for (int i=0; i < size; i++){
		if (stopOperator(userInput[i]) == false){
			throw std::invalid_argument("Invalid character.");
		}

		else if(userInput[i] == ')'){
			Stack<Item> tempStack;
			Item tempItem;
			char tempChar;
			int counter = i;

			while (tempChar != '('){
				tempItem = itemQ.top();
				itemQ.pop();
				tempStack.push(tempItem);
				counter--;
				tempChar = userInput[counter];
			}

		mathVector result;

		result = calculator(tempStack);
		Item *newItem = new Item(result);
		itemQ.push(*newItem);



		}

		else if (userInput[i] == '['){
			string tempstring;
			int counter = i;
			while (userInput[counter] != ']'){
				tempstring += userInput[counter];
				counter++;
			}
			tempstring += ']';
			mathVector *newVector = new mathVector(tempstring);
			Item *newItem = new Item;
			newItem->setVector(*newVector);
			itemQ.push(*newItem);

		}
		else if (stopOperator(userInput[i])){
			Item *newItem = new Item;
			newItem->setCharacter(userInput[i]);
			itemQ.push(*newItem);
		}
		else if (checkNumber(userInput[i])){
			int counter = i;
			string tempnumber;
			while(stopOperator(userInput[counter]) == false){
				tempnumber += userInput[i];
				counter++;
			}
			Item *newItem = new Item;
			mathVector *newVector = new mathVector(tempnumber);
			newItem->setVector(*newVector);
			itemQ.push(*newItem);
		}
	}




	return 0;
}


/*
// random initialized vectors for testing
	mathVector *vector1 = new mathVector("[1.1,2.2,3.3]");
	mathVector *vector2 = new mathVector(*vector1);
	mathVector *vector3 = new mathVector(111.2);
	mathVector *vector4 = new mathVector(1);				//default constructor is normally size 3
	mathVector *vector5 = new mathVector("[9.9,8.8,7.7]");

// addition and subtraction test
	cout << endl;
	cout << "subtraction test" << endl;
	mathVector vector7 = (*vector1 - *vector2);
	cout << vector7.toString() << endl;

// addition test
	cout << endl;
	cout << "addition test" << endl;
	mathVector vector6 = *vector1 + *vector2;
	cout << vector6.toString() << endl;

// 3 by 3 multiplication test
	cout << endl;
	cout << "3 by 3 multiplication test" << endl;
	*vector4 = (*vector1 * *vector5);
	cout << vector4->toString() << endl;

// check if ==
	cout << endl;
	cout << "equality test" << endl;
	cout << (*vector1 == *vector2) << endl;

// checking if 1 by 3 ==
	try{
		cout << (*vector1 == *vector3) << endl;
	} catch(std::invalid_argument& e) {
		e.what();
	}
*/
