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
	for (int i=0; i<7; i++){
		if (array[i] == input){
			return true;
		}
	}
	return false;
}

mathVector calculate(Stack<Item> input){
/*
	cout << input.top().getVector().toString() << endl;
	input.pop();
	cout << input.top().getCharacter() << endl;
	input.pop();
	cout << input.top().getVector().toString() << endl;
	input.pop();
*/

	mathVector subitem1;
	mathVector subitem3;
	char subitem2;

	Item item1 = input.top();
	if (item1.checkVector()){
		subitem1 = item1.getVector();
	}
	input.pop();

	Item item2 = input.top();
	if (!item2.checkVector()){
		subitem2 = item2.getCharacter();
	}
	input.pop();

	Item item3 = input.top();
	if (item3.checkVector()){
		subitem3 = item3.getVector();
	}
	input.pop();

//	cout << item1.getVector().toString() << endl;
//	cout << item2.getCharacter() << endl;
//	cout << item3.getVector().toString() << endl;

	switch (subitem2){
		case '+': {
			mathVector *returnVector = new mathVector(subitem3 + subitem1);
			return *returnVector;
		}
		case '-': {
			mathVector *returnVector = new mathVector(subitem3 - subitem1);
			return *returnVector;
		}
		case '*': {
			mathVector *returnVector = new mathVector(subitem3 * subitem1);
			return *returnVector;
		}
	}
	throw std::invalid_argument("calculator.cpp:83 Nothing to return.");
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
	mathVector result;

	for (int i=0; i < size; i++){
	/*
		if (stopOperator(userInput[i]) == false){
			throw std::invalid_argument("Invalid character.");
		}
	*/

		//cout << i << endl;
		if(userInput[i] == ')'){
			Stack<Item> tempStack;
			Item tempItem;


			while (itemQ.top().getCharacter() != '('){
					tempItem = itemQ.top();
					itemQ.pop();
					tempStack.push(tempItem);
			}
				itemQ.pop();
			result = calculate(tempStack);
			Item *newItem = new Item(result);
			itemQ.push(*newItem);
			cout << result.toString() << endl;
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
		//	cout<<"operator"<<endl;
			Item *newItem = new Item;
			newItem->setCharacter(userInput[i]);
			itemQ.push(*newItem);

		}
		else if (checkNumber(userInput[i])){
			int counter = i;
			string tempnumber;
			while(stopOperator(userInput[counter]) == false){
				tempnumber += userInput[counter];
				counter++;
			}
			double newnumber = atof(tempnumber.c_str());
			Item *newItem = new Item;
			mathVector *newVector = new mathVector(newnumber);
			newItem->setVector(*newVector);
			itemQ.push(*newItem);
			i = counter-1;

		}

	}

	Item finalItem = itemQ.top();
	mathVector finalVector = finalItem.getVector();
	cout << "Final calculation is: " << finalVector.toString() << endl;


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
