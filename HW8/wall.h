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
#include "mergesort.h"
#include <functional>
#include <vector>
#include <iostream>
#include <cstdlib>

class Wall{
	public:
		Wall();
		~Wall();
		void addPost(std::string wallmessage, std::string author);	//insert();
		void removePost(int id);	//remove();
		void removeFriendPost(int, std::string);

		void printWallPosts();	//get();

		void exporttoString(std::ofstream *);
		void importfromString(std::string, std::string, std::string, std::string);
		void importComment(std::string [], int);

		void commentOnWallPost(std::string, std::string, std::string);

		void exportWallComments(std::ofstream*);
		void removeCommentonFriendPost(int, int, std::string);

		int getWallPostSize();


		void sort(bool(*POINTER)(WallPost*, WallPost*));


	private:
		LinkedList<WallPost*> *UserWallPosts;
		int wallCounter;

};


#endif /* WALL_H_ */
