/*
 * wall.h
 *
 *  Created on: Sep 22, 2013
 *      Author: BryanChong
 */

#ifndef WALL_H_
#define WALL_H_

#include <string>
#include "linklist.h"
#include "wallpost.h"

class Wall{
	public:
		Wall();
		~Wall();
		void addPost(std::string wallmessagem, std::string author);
		void removePost(int id);
		void printWallPosts();
		void exporttoString();
		void importtoString();
	private:
		LinkedList<WallPost*> *UserWallPosts;
		int wallCounter;

};


#endif /* WALL_H_ */
