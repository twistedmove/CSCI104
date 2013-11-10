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
#include <iterator>

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
	if (Friends->isEmpty() == true){
		std::cout << "You have no friends. Go make friends!" << std::endl;
	}
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
	if (PendingFriends->isEmpty() == false){
			std::cout << "Here are potential friends in your pending list." << std::endl;
			for (Iterator<User*> i = PendingFriends->begin(); i != PendingFriends->end(); ++i){
				std::cout << (*i)->getusername() << std::endl;
			}
			std::cout << std::endl;
	}
}

void User::acceptFriendRequest(){
	std::string userinput;

	if (PendingFriends->isEmpty() == false){
		std::cout << "Please enter the name you would like to ACCEPT from your pending friend requests." << std::endl;
		std::cout << "Press c to cancel." << std::endl;
		std::cout << "Entry: ";
		std::cin >> userinput;

		for (Iterator<User*> j = PendingFriends->begin(); j != PendingFriends->end(); ++j){
			if ((*j)->getusername() != ""){
				if (userinput == "c"){
					std::cout << "Action canceled." << std::endl;
					std::cout << std::endl;
				}
				else if (userinput != (*j)->getusername()){
					std::cout << "No user exists in pending friends list. Please try again." << std::endl;
				}
				else if (userinput == (*j)->getusername()){
					Friends->push_back(*j);
					PendingFriends->removeObject((*j));
					std::cout << userinput << " is now your friend!" << std::endl;
					std::cout << std::endl;
				}
			}
		}
	}
}

void User::removePendingRequest(){
	std::string userinput;

	if (pendingEmpty() == false){
		std::cout << "Please enter the name you would like to REMOVE from your pending friend requests." << std::endl;
		std::cout << "Press c to cancel." << std::endl;
		std::cout << "Entry: ";
		std::cin >> userinput;
		std::cout << std::endl;

		for (Iterator<User*> i = PendingFriends->begin(); i != PendingFriends->end(); ++i){
				if (userinput == "c"){
					std::cout << "Action canceled." << std::endl;
					std::cout << std::endl;
				}
				else if (userinput != (*i)->getusername()){
					std::cout << "No user exists in pending friends list. Please try again." << std::endl;
				}
				else if (userinput == (*i)->getusername()){
					PendingFriends->removeObject((*i));
					for (Iterator<User*> j = PendingFriends->begin(); j != PendingFriends->end(); ++j){
						if ((*j)->getusername() == userinput){
							std::string thisUser;
							thisUser = (*i)->getusername();
							(*j)->removeUserFromFriendList(thisUser);
						}
					}
					std::cout << userinput << "has been successfully removed from your pending friends list." << std::endl;
				}
		}
	}
}

void User::removeUserFromFriendList(std::string deletethisUser){
	for (Iterator<User*> i = PendingFriends->begin(); i != PendingFriends->end(); ++i){
		if (deletethisUser == (*i)->getusername()){
			Friends->removeObject((*i));
		}
	}
}


bool User::removeFriend(std::string userinput){
		if (userinput == "c"){
			std::cout << "Action canceled." << std::endl;
			return false;
		}
		if (userinput == ""){
			std::cout << "No input. Returning to menu." << std::endl;
			return false;
		}

		for (Iterator<User*> i = Friends->begin(); i != Friends->end(); ++i){
			std::cout << (*i)->getusername() << std::endl;
		}

		for (Iterator<User*> i = Friends->begin(); i != Friends->end(); ++i){
			if (userinput != (*i)->getusername()){
				std::cout << "No user exists in friends list. Please try again." << std::endl;
				return false;
			}
			else if (userinput == (*i)->getusername()){
				Friends->removeObject((*i));
				return true;
			}
		}

		return false;
}

bool User::isFriend(std::string f){
	for (Iterator<User*> i = Friends->begin(); i != Friends->end(); ++i){
		if ((*i)->getusername() == f){
			return true;
		}
	}
	return false;

}


bool User::pendingEmpty(){
	if (PendingFriends->isEmpty()){
		return true;
	}
	else
		return false;
}

void User::setfriendlist(std::string flist){
	friendlist = flist;
}

void User::setpendinglist(std::string plist){
	pendinglist = plist;
}

std::string User::getfriendlist(){
	return friendlist;
}

std::string User::getpendinglist(){
	return pendinglist;
}

#endif /* USER_CPP_ */
