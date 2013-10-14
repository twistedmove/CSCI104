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
		bool isVector();

	private:
		std::string character;
		mathVector vector;
};

bool Item::isVector(){
	if (vector != NULL){
		return true;
	}
	return false;
}



#endif /* ITEM_H_ */
