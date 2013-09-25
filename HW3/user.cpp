/*
 * user.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: BryanChong
 */

#ifndef USER_CPP_
#define USER_CPP_

#include "user.h"
#include "wall.h"
#include <iostream>
#include <string>

User::User(){
	UserWall = new Wall;
}

User::~User(){
	delete UserWall;
}

void User::addWallPost(std::string wallmessage){
	UserWall->addPost(wallmessage,username);
}

void User::removeWallPost(int id){
	UserWall->removePost(id);
}

std::string User::returnUsername(){
	return username;
}

Wall* User::getWall(){
	return UserWall;
}

void User::printInformation(){
	std::cout << "Information List: Do not share this information." << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Username: " << username << std::endl;
	std::cout << "Password: " << password << std::endl;
	std::cout << "Address: " << address << std::endl;
	std::cout << "Email: " << email << std::endl;
	std::cout << "------------------------------------------------" << std:: endl;

}

void User::setUsername(std::string usern){
	username = usern;
}

void User::editInformation(){
	std::cout << "Enter your new password." << std::endl;
	std::cin >> password;
	std::cout << "Enter your new address." << std::endl;
	std::cin >> address;
	std::cout << "Enter your new email." << std::endl;
	std::cin >> email;

	std::cout << "Information List: Do not share this information." << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Username: " << username << std::endl;
	std::cout << "Password: " << password << std::endl;
	std::cout << "Your address is: " << address << std::endl;
	std::cout << "Email: " << email << std::endl;
}



#endif /* USER_CPP_ */
