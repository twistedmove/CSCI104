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
#include <cstdlib>
#include <fstream>

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

void User::exportWall(std::ofstream * exportFile){
	UserWall->exporttoString(exportFile);
}

void User::importWall(std::string array[]){
	std::string aid;
	std::string bauthor;
	std::string cmessage;
	aid = array[0];
	bauthor = array[1];
	cmessage = array[2];

//	std::cout << cmessage << " in user.cpp" << std::endl;

//	std::cout << "user.cpp" <<std::endl;

	UserWall->importfromString(aid,bauthor,cmessage);
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
	char tempaddress[512];

	std::cout << "Enter your new password." << std::endl;
	std::cin >> password;
	std::cout << "Enter your new address." << std::endl;
	std::cin.ignore();		//skips the enter
	std::cin.getline(tempaddress,512);
	address = tempaddress;
	std::cout << "Enter your new email." << std::endl;
	std::cin >> email;

	std::cout << "Information List: Do not share this information." << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Username: " << username << std::endl;
	std::cout << "Password: " << password << std::endl;
	std::cout << "Your address is: " << address << std::endl;
	std::cout << "Email: " << email << std::endl;
}

std::string User::exportprintUser(){
	std::string tempholder;
	tempholder = username + "`" + password + "`" + address + "`" + email;
	return tempholder;
}

void User::setusername(std::string newusername){
	username = newusername;
}

void User::setpassword(std::string newpassword){
	password = newpassword;
}

void User::setaddress(std::string newaddress){
	address = newaddress;
}

void User::setemail(std::string newemail){
	email = newemail;
}


#endif /* USER_CPP_ */
