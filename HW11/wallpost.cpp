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
	wprawtime = 0;
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

void WallPost::setRawTime(time_t r){
	wprawtime = r;
}

void WallPost::setRawTime(std::string r){
	int tt;
	tt = atoi(r.c_str());

	time_t rawtime = tt;
	wprawtime = rawtime;
}

void WallPost::setTime(std::string r){
	long int tt;
	tt = atoi(r.c_str());

	time_t rawtime = tt;
	std::string rtime = ctime(&rawtime);

	wptime = rtime;
}


std::string WallPost::getTime(){
	return wptime;
}

time_t WallPost::getRawTime(){
	return wprawtime;
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
	std::cout << "*------------------------------------------------------------*" << std::endl;
	std::cout << "* ID: " << id << std::endl;
	std::cout << "* Author: " << author << std::endl;
	std::cout << "* Message: " << wallmessage << std::endl;
	std::cout << "* Time: " << wptime << std::endl;
	std::cout << "*------------------------------------------------------------*" << std::endl;
	for (Iterator<WallPostComments*> i = UserComments->begin(); i != UserComments->end(); ++i){
		(*i)->readWallPostComments();
	}
	//std::cout << std::endl;
}

std::string WallPost::intToString(int number){
	std::stringstream ss;
	ss << number;
	return ss.str();
}


// every '|' is a new wallpost
std::string WallPost::exportprintWallPost(){
	std::string tempholder;
	std::stringstream ss;
	std::string stringrtime;

	stringrtime = intToString(wprawtime);

	ss << id;
	ss >> tempholder;
	tempholder += "`" + author + "`" + wallmessage + "`" + stringrtime;
	return tempholder;
}

std::string WallPost::exporttoString(){
	std::string tempvalue;
	for (Iterator<WallPostComments*> i = UserComments->begin(); i != UserComments->end(); ++i){
		tempvalue += (*i)->exportprintWallPostComments();
		tempvalue += "|";
	}
	return tempvalue;
}

void WallPost::importCommentsfromString(std::string a,std::string b,std::string c,std::string d){
	WallPostComments *newWallPostComment = new WallPostComments;

	int intid;
	std::stringstream(a) >> intid;


	newWallPostComment->setID(intid);
	newWallPostComment->setAuthor(b);
	newWallPostComment->setComment(c);
	newWallPostComment->importTime(d);


	UserComments->push_back(newWallPostComment);
	commentidCounter++;
}

void WallPost::deleteCommentPost(int id, std::string auth){
	for (Iterator<WallPostComments*> i = UserComments->begin(); i != UserComments->end(); ++i){
		if(id == (*i)->getID()){
			if (auth != (*i)->getAuthor()){
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "You are not the author of this post." << std::endl;
				std::cout << "ACCESS DENIED." << std::endl;
				return;
			}
			else if (auth == (*i)->getAuthor()){
				UserComments->removeObject(*i);
				std::cout << "Success" << std::endl;
				return;
			}
		}
	}
}

int WallPost::returnTime(){
	int time;
	time = wprawtime;
	return time;
}

int WallPost::returnCreation(){
	int time;
	time = wprawtime;
	return time;
}

void WallPost::addComment(std::string comment, std::string author){
	WallPostComments *tempcomment = new WallPostComments;

	time_t rawtime = time(&rawtime);
	std::string rtime = ctime(&rawtime);


	tempcomment->setRawTime(rawtime);
	tempcomment->setTime(rtime);
	tempcomment->setComment(comment);
	tempcomment->setAuthor(author);
	tempcomment->setID(commentidCounter++);
	UserComments->push_back(tempcomment);
}

#endif /* WALLPOST_CPP_ */
