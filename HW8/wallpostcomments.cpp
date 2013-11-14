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
#include <string>
#include <time.h>
#include <stdio.h>


WallPostComments::WallPostComments(){
	id = -1;
	rawtime = 0;
//	totalseconds = 0;
//	dayofyear = 0;
//	year = 13;
//	month = 0;
//	day = 0;
}

WallPostComments::~WallPostComments(){}


void WallPostComments::readWallPostComments(){
	std::cout << "   >>>> " << "ID: " << id << std::endl;
	std::cout << "   >>>> " << "User: " << author << std::endl;
	std::cout << "   >>>> " << "Time: " << time;
	std::cout << "   >>>> " << comment << std::endl;
	std::cout << "*---------------------------------------------------------*" << std::endl;
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

void WallPostComments::setRawTime(time_t h){
	rawtime = h;
}



time_t WallPostComments::getRawTime(){
	return rawtime;
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

std::string WallPostComments::intToString(int number){
	std::stringstream ss;
	ss << number;
	return ss.str();
}

void WallPostComments::importTime(std::string curtime){
	long int tt;
	tt = atoi(curtime.c_str());

	time_t rwtime = tt;
	std::string rtime = ctime(&rwtime);

	rawtime = rwtime;
	time = rtime;
}

void WallPostComments::printWallPostComments(){
	std::cout << "*---------------------------------------------------------*" << std::endl;
	std::cout << "* ID: " << id << std::endl;
	std::cout << "* Author: " << author << std::endl;
	std::cout << "* Message: " << comment << std::endl;
	std::cout << "*---------------------------------------------------------*" << std::endl;
	std::cout << std::endl;
}


// every ';' is a new wallpost
std::string WallPostComments::exportprintWallPostComments(){
	std::string tempholder;
	std::stringstream ss;
	std::string tiempo;

	tiempo = intToString(rawtime);

	ss << id;
	ss >> tempholder;
	tempholder += "`" + author + "`" + comment + "`" + tiempo;


	return tempholder;
}
