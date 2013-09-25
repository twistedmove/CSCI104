/*
 * wallpost.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: BryanChong
 */

#ifndef WALLPOST_CPP_
#define WALLPOST_CPP_

#include <iostream>
#include "wallpost.h"


WallPost::WallPost(){
	id = -1;
}

WallPost::~WallPost(){}

void WallPost::readWallPost(){
	std::cout << "User " << author << "left you a message!" << std::endl;
	std::cout << "Your message is: " << std::endl;
	std::cout << wallmessage << std::endl;
}

void WallPost::editWallPost(std::string editedMessage){
	wallmessage = editedMessage;
}

void WallPost::setMessage(std::string message){
	wallmessage = message;
}

void WallPost::setAuthor(std::string a){
	author = a;
}

void WallPost::setID(int wallCounter){
	id = wallCounter;
}

int WallPost::getID(){
	return id;
}

std::string WallPost::getAuthor(){
	return author;
}

std::string WallPost::getMessage(){
	return wallmessage;
}

void WallPost::printWallPost(){
	std::cout << "ID: " << id << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Message: " << wallmessage << std::endl;
}

#endif /* WALLPOST_CPP_ */
