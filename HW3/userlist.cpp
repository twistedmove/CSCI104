/*
 * userlist.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: BryanChong
 */

#ifndef USERLIST_CPP_
#define USERLIST_CPP_

#include "userlist.h"
#include "user.h"
#include "linklist.h"
#include <iostream>
#include <cstdlib>
#include <fstream>


UserList::UserList(){
	UserLinkList = new LinkedList<User>;
}

UserList::~UserList(){
	delete UserLinkList;
}

void UserList::exportUserDatabase(){
	UserLinkList->SetIteratorBegin();
	std::ofstream *exportFile = new std::ofstream;
	exportFile->open("database.txt");
			for (int i = 0; i < UserLinkList->size(); i++) {
				std::string tempholder;
				tempholder = UserLinkList->IteratorValue().exportprintUser();
				*(exportFile) << tempholder;
				*(exportFile) << "\n";
				UserLinkList->IteratorValue().exportWall(exportFile);
				*(exportFile) << "\n";
				UserLinkList->IncrementIterator();
				}
	exportFile->close();
	delete exportFile;
}

void UserList::importUserDatabase(){
	std::ifstream importFile("database.txt");
	if (importFile.fail()){
		std::cout << "*-----------------------------*" << std::endl;
		std::cout << "| database.txt does not exist |" << std::endl;
		std::cout << "*-----------------------------*" << std::endl;
	}
	if (importFile.good()){
		while (!importFile.eof()){
			std::string temporary;
			std::string tempitem;
			std::string delimiter = "`";
			std::string postdelimiter = "|";
			std::string temppost;
			std::string userinformationarray[4];
			int counter = 0;
 			std::getline(importFile, temporary, '\n');
			unsigned long int position = 0;

// Parses through the User and gets information
			while ((position = temporary.find(delimiter)) !=  std::string::npos){
				tempitem = temporary.substr(0, position);
				// std::cout << tempitem << std::endl;
				userinformationarray[counter] = tempitem;
				counter++;
				temporary.erase(0, position + delimiter.length());
			}

				// std::cout << temporary << std::endl;
				userinformationarray[counter] = temporary;
				User* newUser = new User;
				newUser->setusername(userinformationarray[0]);
				newUser->setpassword(userinformationarray[1]);
				newUser->setaddress(userinformationarray[2]);
				newUser->setemail(userinformationarray[3]);
				UserLinkList->push_back(*newUser);


			temporary = "";
			position = 0;


// Second line - parses through all the wallposts
			std::getline(importFile, temporary, '\n');


			// gets the string till '|' - which is the first wallpost
			while ((position = temporary.find(postdelimiter)) !=  std::string::npos){
				std::string wallinformationarray[3];
				int newcounter = 0;
				temppost = temporary.substr(0, position);
				// std::cout << temppost << std::endl;
				unsigned long int newpos = 0;
				// this parses everything inside the temppost (e.g id, author, message)
				while ((newpos = temppost.find(delimiter)) !=  std::string::npos){
					tempitem = temppost.substr(0, newpos);
				//	std::cout << tempitem << std::endl;
					wallinformationarray[newcounter] = tempitem;
					newcounter++;
				//	std::cout << wallinformationarray[2] << " in userlist.cpp" << std::endl;

					temppost.erase(0, newpos + delimiter.length());
				}
				// std::cout << temppost << std::endl;
				wallinformationarray[2] = temppost;
				temporary.erase(0, position + postdelimiter.length());
				newUser->importWall(wallinformationarray);
				// std::cout << "userlist.cpp" <<std::endl;
			}


			//newUser->importWall(wallinformationarray[3]);




		}
	}
	importFile.close();
}

void UserList::addUser(User& u){
	std::cout << "Please create your new credentials." << std::endl;
	u.editInformation();
	UserLinkList->push_back(u);
}

void UserList::deleteUser(User& u){
	UserLinkList->removeObject(u);
}

User* UserList::checkUser(std::string username){
	UserLinkList->SetIteratorBegin();
		for (int i = 0; i < UserLinkList->size(); i++) {
			if (username == UserLinkList->IteratorValue().returnUsername()) {
				return &(UserLinkList->IteratorValue());
			}
			UserLinkList->IncrementIterator();
		}
		return NULL;
}

void UserList::removeUser(User* todelete){
	UserLinkList->removeObject(*todelete);
}

#endif /* USERLIST_CPP_ */
