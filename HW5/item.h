/*
 * item.h
 *
 *  Created on: Oct 13, 2013
 *      Author: BryanChong
 */

#ifndef ITEM_H_
#define ITEM_H_

#include "vector.h"
#include <string>


class Item{
	public:
		Item(char);
		~Item();
		bool checkVector();
		void setVector(mathVector vector);
		void setCharacter(char);
		char getCharacter();
		mathVector getVector();

	private:
		bool isVector;
		char character;
		mathVector vector;
};



mathVector Item::getVector(){
	return vector;
}

char Item::getCharacter(){
	return character;
}

void Item::setCharacter(char inputChar){
	character = inputChar;
	isVector = false;
}

void Item::setVector(mathVector importVector){
	vector = importVector;
	isVector = true;
}

bool Item::checkVector(){
	if (isVector == true){
		return true;
	}
	return false;
}



#endif /* ITEM_H_ */
