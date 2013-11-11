/*
 * wallpostcomments.cpp
 *
 *  Created on: Nov 10, 2013
 *      Author: BryanChong
 */

#include <iostream>
#include "wallpost.h"
#include <cstdlib>
#include <sstream>
#include <time.h>


WallPostComments::WallPostComments(){
	id = -1;
}

WallPostComments::~WallPostComments(){}


void WallPostComments::readWallPostComments(){
	std::cout << "   >>>> " << "ID: " << id << std::endl;
	std::cout << "   >>>> " << "User: " << author << std::endl;
	std::cout << "   >>>> " << "Time: " << time << std::endl;
	std::cout << "   >>>> " << comment << std::endl;
}

void WallPostComments::editWallPostComments(std::string editedMessage){
	comment = editedMessage;
}

void WallPostComments::setComment(std::string message){
	comment = message;
}

void WallPostComments::setAuthor(std::string a){
	author = a;
}

void WallPostComments::setID(int wallCounter){
	id = wallCounter;
}

void WallPostComments::setTime(std::string curtime){
	time = curtime;
}

void WallPostComments::setHour(std::string t){
	hour = t;
}

void WallPostComments::setMinute(std::string t){
	minute = t;
}

void WallPostComments::setSecond(std::string t){
	second = t;
}

std::string WallPostComments::getHour(){
	return hour;
}

std::string WallPostComments::getMinute(){
	return minute;
}

std::string WallPostComments::getSecond(){
	return second;
}

std::string WallPostComments::getTime(){
	return time;
}

int WallPostComments::getID(){
	return id;
}


std::string WallPostComments::getAuthor(){
	return author;
}

std::string WallPostComments::getMessage(){
	return comment;
}


void WallPostComments::printWallPostComments(){
	std::cout << "ID: " << id << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Message: " << comment << std::endl;
	std::cout << std::endl;
}


// every ';' is a new wallpost
std::string WallPostComments::exportprintWallPostComments(){
	std::string tempholder;
	std::stringstream ss;
	ss << id;
	ss >> tempholder;
	tempholder += "`" + author + "`" + comment + "`" + hour  + "`" + minute  + "`" + second;
	return tempholder;
}
