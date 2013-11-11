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
#include <cstdlib>
#include <sstream>
#include <iterator>
#include <time.h>


WallPost::WallPost(){
	UserComments = new LinkedList<WallPostComments*>;
	id = -1;
	commentidCounter = 0;
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
	for (Iterator<WallPostComments*> i = UserComments->begin(); i != UserComments->end(); ++i){
		(*i)->readWallPostComments();
	}
	std::cout << std::endl;
}


// every ';' is a new wallpost
std::string WallPost::exportprintWallPost(){
	std::string tempholder;
	std::stringstream ss;
	ss << id;
	ss >> tempholder;
	tempholder += "`" + author + "`" + wallmessage;
	return tempholder;
}

void WallPost::addComment(std::string comment, std::string author){
	WallPostComments *tempcomment = new WallPostComments;
	char tt[4];
	char th[4];
	char ts[4];
	std::string finaltime;
	std::string h;
	std::string m;
	std::string s;

	time_t rawtime = time(&rawtime);
    tm *pTime = localtime(&rawtime);
    sprintf(tt, "%d", pTime->tm_hour);
    sprintf(th, "%d", pTime->tm_min);
    sprintf(ts, "%d", pTime->tm_sec);

    finaltime = tt;
    finaltime += ":";
    finaltime += th;
    finaltime += ":";
    finaltime += ts;

    h = tt;
    m = th;
    s = ts;


	tempcomment->setTime(finaltime);
	tempcomment->setHour(h);
	tempcomment->setMinute(m);
	tempcomment->setSecond(s);
	tempcomment->setComment(comment);
	tempcomment->setAuthor(author);
	tempcomment->setID(commentidCounter++);
	UserComments->push_back(tempcomment);
}

#endif /* WALLPOST_CPP_ */
