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
	Friends = new LinkedList<User*>;
	PendingFriends = new LinkedList<User*>;
}



User::~User(){
	delete UserWall;
	delete Friends;
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

void User::importFriends(User* ifriend){
	Friends->push_back(ifriend);
}

void User::importPendingFriends(User* pfriend){
	PendingFriends->push_back(pfriend);
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


void User::exportFriendList(std::ofstream * exportFile){
//		*(exportFile) << '>';
	for (Iterator<User*> i = Friends->begin(); i != Friends->end(); ++i){
			std::string tempvalue;
			tempvalue = (*i)->getusername();
			*(exportFile) << tempvalue;
			*(exportFile) << "|";
	}
}

void User::exportPendingList(std::ofstream * exportFile){
	//		*(exportFile) << '<';
		for (Iterator<User*> i = PendingFriends->begin(); i != PendingFriends->end(); ++i){
				std::string tempvalue;
				tempvalue = (*i)->getusername();
				*(exportFile) << tempvalue;
				*(exportFile) << "|";
		}
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

void User::addFriend(User* newFriend){
	Friends->push_back(newFriend);
}

std::string User::getusername(){
	return username;
}

void User::displayFriends(){
//	std::cout << "entered" << std::endl;
	if (Friends->isEmpty() == false){
//		std::cout << "inside" << std::endl;
		for (Iterator<User*> i = Friends->begin(); i != Friends->end(); ++i){
			std::cout << (*i)->getusername() << std::endl;
		}
	}
//	std::cout << "outside" << std::endl;
}

void User::addPendingFriend(User* pendingFriend){
	PendingFriends->push_back(pendingFriend);
}

void User::displayPendingFriends(){
	if (Friends->isEmpty() == false){
		{
			for (Iterator<User*> i = PendingFriends->begin(); i != PendingFriends->end(); ++i){
				std::cout << (*i)->getusername() << std::endl;
			}
		}
	}
}

void User::acceptFriendRequest(){
	std::string userinput;

	for (Iterator<User*> i = PendingFriends->begin(); i != PendingFriends->end(); ++i){
		std::cout << "Here are your pending friend requests:" << (*i)->getusername() << std::endl;
	}

		std::cout << "Please enter the name you would like to accept." << std::endl;
		std::cin >> userinput;

		for (Iterator<User*> i = PendingFriends->begin(); i != PendingFriends->end(); ++i){
				if (userinput != (*i)->getusername()){
					std::cout << "No user exists in pending friends list. Please try again." << std::endl;
				}
				else if (userinput == (*i)->getusername()){
					Friends->push_back(*i);
					PendingFriends->removeObject((*i));
				}
		}
}

void User::removePendingRequest(){
	std::string userinput;

	for (Iterator<User*> i = PendingFriends->begin(); i != PendingFriends->end(); ++i){
			std::cout << "Here are your pending friend requests:" << (*i)->getusername() << std::endl;
	}

	std::cout << "Please enter the name you would like to remove." << std::endl;
	std::cin >> userinput;

	for (Iterator<User*> i = PendingFriends->begin(); i != PendingFriends->end(); ++i){
				if (userinput != (*i)->getusername()){
					std::cout << "No user exists in pending friends list. Please try again." << std::endl;
			}
				else if (userinput == (*i)->getusername()){
					PendingFriends->removeObject((*i));
			}
	}

}

void User::removeFriend(){
	std::string userinput;

//	if (Friends->isEmpty() == false){
		for (Iterator<User*> i = Friends->begin(); i != Friends->end(); ++i){
			std::cout << (*i)->getusername() << std::endl;
		}

		std::cout << "Please enter the name you would like to remove." << std::endl;
		std::cin >> userinput;

		for (Iterator<User*> i = Friends->begin(); i != Friends->end(); ++i){
						if (userinput != (*i)->getusername()){
							std::cout << "No user exists in friends list. Please try again." << std::endl;
					}
						else if (userinput == (*i)->getusername()){
							Friends->removeObject((*i));
					}
		}
//	}
}

bool User::pendingEmpty(){
	if (PendingFriends->isEmpty()){
		return true;
	}
	else
		return false;
}

void User::setfriendlist(std::string flist){
	std::cout << "2. friend: " << flist << std::endl;
	friendlist = flist;
	std::cout << "3. friend: " << friendlist << std::endl << std::endl;
}

void User::setpendinglist(std::string plist){
//	std::cout << "2. pending: " << plist << std::endl;
	pendinglist = plist;
//	std::cout << "3. pending: " << pendinglist << std::endl;
}

std::string User::getfriendlist(){
	std::cout << "4. friend: " << friendlist << std::endl;
	return friendlist;
}

std::string User::getpendinglist(){
//	std::cout << "4. pending: " << pendinglist << std::endl;
	return pendinglist;
}

#endif /* USER_CPP_ */
