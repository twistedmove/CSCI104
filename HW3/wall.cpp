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
	UserWallPosts->SetIteratorBegin();
			for (int i = 0; i < UserWallPosts->size(); i++) {
				if (id == UserWallPosts->IteratorValue()->getID()) {
					UserWallPosts->removeObject(UserWallPosts->IteratorValue());
				}
					UserWallPosts->IncrementIterator();
			}
}

void Wall::printWallPosts(){
	UserWallPosts->SetIteratorBegin();
			for (int i = 0; i < UserWallPosts->size(); i++) {
					UserWallPosts->IteratorValue()->printWallPost();
				UserWallPosts->IncrementIterator();
			}
}

void Wall::readtoString(){

}

void Wall::writetoString(){

}


#endif /* WALL_CPP_ */
