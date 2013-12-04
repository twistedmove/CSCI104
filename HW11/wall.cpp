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
#include "mergesort.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include "priorityQ.h"
#include <time.h>

Wall::Wall(){
	UserWallPosts = new LinkedList<WallPost*>;
	wallCounter = 0;
}



Wall::~Wall(){
	delete UserWallPosts;
}

int Wall::getWallPostSize(){
	int count = 0;
	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		count++;
	}
	return count;
}


void Wall::sort(bool(*POINTER)(WallPost* A, WallPost* B)){

	int counter = 0;
	Heap<WallPost*> *h = new Heap<WallPost*>(2,true);

	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		h->add((*i),POINTER);
	}

	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		counter++;
			h->peek()->printWallPost();
			h->remove(POINTER);
	}


	//delete h;


}

void Wall::addPost(std::string message, std::string author){
	WallPost *tempwallpost = new WallPost;

	time_t rawtime = time(&rawtime);
	std::string rtime = ctime(&rawtime);


	tempwallpost->setRawTime(rawtime);
	tempwallpost->setTime(rtime);
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

void Wall::removeFriendPost(int id, std::string author){
	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		if (id == (*i)->getID()){
			if (author != (*i)->getAuthor()){
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "You are not the author of this post." << std::endl;
				std::cout << "ACCESS DENIED." << std::endl;
				return;
			}
			else if (author == (*i)->getAuthor()){
				UserWallPosts->removeObject(*i);
				return;
			}
		}
	}
}

void Wall::removeCommentonFriendPost(int id, int id2, std::string author){
	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		if (id == (*i)->getID()){
			(*i)->deleteCommentPost(id2, author);
		}
	}
}



void Wall::printWallPosts(){



	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		(*i)->printWallPost();
	}
}

void Wall::importfromString(std::string id, std::string author, std::string message, std::string time){
	WallPost *newWallPost = new WallPost;
	UserWallPosts->push_back(newWallPost);

	int intid;
	std::stringstream(id) >> intid;

//	std::cout << message << " in wall.cpp" << std::endl;

	newWallPost->setID(intid);
	newWallPost->setAuthor(author);
	newWallPost->setMessage(message);
	newWallPost->setTime(time);
	newWallPost->setRawTime(time);
	wallCounter++;
}

void Wall::importComment(std::string array[], int n){
	std::string id;
	std::string author;
	std::string comment;
	std::string time;

	id = array[0];
	author = array[1];
	comment = array[2];
	time = array[3];

	Iterator<WallPost*> i = UserWallPosts->begin();

	for (int j = 0; j < n; j++){
		++i;
	}

	if (i != UserWallPosts->end()){
		(*i)->importCommentsfromString(id, author, comment, time);
	}

}


void Wall::exporttoString(std::ofstream * exportFile){
	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		std::string tempvalue;
		tempvalue = (*i)->exportprintWallPost();
		*(exportFile) << tempvalue;
		*(exportFile) << "|";
	}
}

void Wall::exportWallComments(std::ofstream * exportFile){
	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		*(exportFile) << (*i)->exporttoString();
		*(exportFile) << "~";
	}
}


void Wall::commentOnWallPost(std::string id, std::string usern ,std::string author){
	char tempcomment[1024];
	std::string comment;
	int result;

	result = atoi(id.c_str()); // convert string to int


	std::cout << "Please enter your comment. (Max of 1024 characters)" << std::endl;
	std::cin.ignore();		//skips the enter
	std::cin.getline(tempcomment,1024);
	comment = tempcomment;

	for (Iterator<WallPost*> i = UserWallPosts->begin(); i != UserWallPosts->end(); ++i){
		if ((*i)->getID() == result){
			(*i)->addComment(comment, author);
		}
	}
}


#endif /* WALL_CPP_ */
