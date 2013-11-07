/*
 * wall.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: BryanChong
 */

#ifndef WALL_CPP_
#define WALL_CPP_

#include "wall.h"
#include "linklist.h"
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

Wall::Wall(){
	UserWallPosts = new LinkedList<WallPost*>;
	wallCounter = 0;
}



Wall::~Wall(){
	delete UserWallPosts;
}


void Wall::addPost(std::string message, std::string author){
	WallPost *tempwallpost = new WallPost;
	tempwallpost->setMessage(message);
	tempwallpost->setAuthor(author);
	tempwallpost->setID(wallCounter++);
	UserWallPosts->push_back(tempwallpost);

}

void Wall::removePost(int id){

	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		if (id == (*i)->getID()){
			UserWallPosts->removeObject(*i);
			return;
		}
	}

}

void Wall::printWallPosts(){

	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		(*i)->printWallPost();
	}
}

void Wall::importfromString(std::string id, std::string author, std::string message){
	WallPost *newWallPost = new WallPost;
	UserWallPosts->push_back(newWallPost);

	int intid;
	std::stringstream(id) >> intid;

//	std::cout << message << " in wall.cpp" << std::endl;

	newWallPost->setID(intid);
	newWallPost->setAuthor(author);
	newWallPost->setMessage(message);
	wallCounter++;
}


void Wall::exporttoString(std::ofstream * exportFile){
	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		std::string tempvalue;
		tempvalue = (*i)->exportprintWallPost();
		*(exportFile) << tempvalue;
		*(exportFile) << "|";
	}


}


#endif /* WALL_CPP_ */
