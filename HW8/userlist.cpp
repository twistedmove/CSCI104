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
#include <algorithm>
#include <iterator>


UserList::UserList(){
	UserLinkList = new LinkedList<User>;
}

UserList::~UserList(){
	delete UserLinkList;
}


bool UserList::is_Empty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

void UserList::exportUserDatabase(){
	std::ofstream *exportFile = new std::ofstream;
	exportFile->open("database.txt");

	if (UserLinkList->size() != 0){
		for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
			if((*i).getusername() != ""){
				std::string tempholder;
				tempholder = (*i).exportprintUser();
				*(exportFile) << "\n";
				*(exportFile) << tempholder;
				*(exportFile) << "\n";
				(*i).exportWall(exportFile);
				*(exportFile) << "\n";
				(*i).exportFriendList(exportFile);
				*(exportFile) << "\n";
				(*i).exportPendingList(exportFile);
			}
			if ((*i).getusername() == ""){
				UserLinkList->decSize();
			}
		}
//		std::cout << "UserList size is: << UserLinkList->size() << std::endl;
	}
	exportFile->close();
	delete exportFile;
}

void UserList::importUserDatabase(){
	std::ifstream importFile("database.txt");
	std::string junk;
	if (importFile.fail()){
		std::cout << "*-----------------------------*" << std::endl;
		std::cout << "| database.txt does not exist |" << std::endl;
		std::cout << "*-----------------------------*" << std::endl;
	}
	if (!is_Empty(importFile)){
	if (importFile.good()){
		std::getline(importFile, junk);
		while (!importFile.eof()){
			std::string temporary;
			std::string tempitem;
			std::string delimiter = "`";
			std::string postdelimiter = "|";
			std::string temppost;
			std::string tempfriend;
			std::string temppending;
			std::string userinformationarray[4];
			int counter = 0;
			unsigned long int position = 0;

// Parses through the User and gets information
			std::getline(importFile, temporary, '\n');
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


			temporary = "";
			position = 0;


// Second line - parses through all the wallposts
			std::getline(importFile, temporary, '\n');
			while ((position = temporary.find(postdelimiter)) !=  std::string::npos){		// gets the string till '|' - which is the first wallpost
					std::string wallinformationarray[3];
					int newcounter = 0;
					temppost = temporary.substr(0, position);
					unsigned long int newpos = 0;
				while ((newpos = temppost.find(delimiter)) !=  std::string::npos){			// this parses everything inside the temppost (e.g id, author, message)
					tempitem = temppost.substr(0, newpos);
					wallinformationarray[newcounter] = tempitem;
					newcounter++;
					temppost.erase(0, newpos + delimiter.length());
				}
				wallinformationarray[2] = temppost;
				temporary.erase(0, position + postdelimiter.length());
				newUser->importWall(wallinformationarray);
			}



// Third line - saves friends list
			std::getline(importFile, temporary, '\n');
			//std::cout << newUser->getusername() << std::endl;
			newUser->setfriendlist(temporary);

// Fourth line - saves pending friends list
			std::getline(importFile, temporary, '\n');
			newUser->setpendinglist(temporary);




			UserLinkList->push_back(*newUser);

	//		std::cout << newUser->getusername() << " ::: " << newUser->getfriendlist() << " :::: " << std::endl;


		} 		// while !importfile.eof
	} 			// end of if importfile.good();
	}
	importFile.close();
}				// end of importUserDatabase function

void UserList::completeList(){
	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		std::string friendlist;
		std::string pendinglist;

		friendlist = (*i).getfriendlist();
		pendinglist = (*i).getpendinglist();

		std::string tempstring = "default";
		std::string postdelimiter = "|";
		unsigned long int position = 0;

		if (friendlist != ""){
			while ((position = friendlist.find(postdelimiter)) !=  std::string::npos && tempstring != ""){
					tempstring = friendlist.substr(0,position);
				if (tempstring != ""){
					for (Iterator<User> j = UserLinkList->begin(); j != UserLinkList->end(); ++j){
						std::string usernameholder = (*j).getusername();
						// find the user in the user data list and save the pointer to that user and push back to the Friends <*User>
						if (usernameholder == tempstring){
							(*i).importFriends(&(*j));
							tempstring.erase(0, position + postdelimiter.length());
						}
						else{
						}
					}
				}
			}
		}

		tempstring = "default";

		if (pendinglist != ""){
			while ((position = pendinglist.find(postdelimiter)) !=  std::string::npos && tempstring != ""){
					tempstring = pendinglist.substr(0,position);
				if (tempstring != ""){
					for (Iterator<User> j = UserLinkList->begin(); j != UserLinkList->end(); ++j){
						std::string usernameholder = (*j).getusername();
						if (usernameholder == tempstring){
							(*i).importPendingFriends(&(*j));
							tempstring.erase(0, position + postdelimiter.length());
						}
						else{
						}
					}
				}
			}
		}


	}
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

	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if (username == (*i).getusername()){
			return &(*i);
		}
	}
		return NULL;
}

void UserList::removeUser(User* todelete){
	UserLinkList->removeObject(*todelete);
}

bool UserList::findUser(std::string findusername, User* currentUser){
	std::string tempuser;
	int counter = 0;
	LinkedList<User> searchResults;
	bool found = false;

	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		tempuser = (*i).getusername();
		if (tempuser.find(findusername) != std::string::npos){
			searchResults.push_back(*i);
			std::cout << counter << ": " << tempuser << std::endl;
			found = true;
		}
		counter++;
	}

	return found;
}

bool UserList::validUser(std::string usercheck){
	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if (usercheck == (*i).getusername()){
			return true;
		}
	}
	return false;

}


std::string UserList::fixString(std::string u){
	std::string s = u;
		for (int unsigned i=0; i<s.length(); i++){	// remove whitespace
	//		cout << s[i] << endl;
			if (s[i] == ' '){
				s.erase(i,1);
			}
		}
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		return s;
}

void UserList::removeFromFriend(std::string f, std::string r){
	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if (f == (*i).getusername()){
			(*i).removeFriend(r);
		}
	}
}


void UserList::displayUserWallPost(std::string f){
	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if ((*i).getusername() == f){
			(*i).getWall()->printWallPosts();
		}
	}
}

void UserList::commentFriendWallPost(std::string wpostid, std::string newuser, std::string author){
	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if ((*i).getusername() == newuser){
			(*i).getWall()->commentOnWallPost(wpostid, newuser, author);
		}
	}
}

void UserList::postFriendWall(std::string post, std::string newuser, std::string author){
	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if ((*i).getusername() == newuser){
			(*i).getWall()->addPost(post, author);
		}
	}
}

void UserList::deleteFriendPost(std::string postid, std::string newuser, std::string author){
	int result;
	result = atoi(postid.c_str());

	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if ((*i).getusername() == newuser){
			(*i).getWall()->removeFriendPost(result, author);
		}
	}
}

bool UserList::checkifFriend(std::string f, std::string cur){
	bool one = false;
	bool two = false;

	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if ((*i).getusername() == f){
			(*i).isFriend(cur);
			one = true;
		}
		if ((*i).getusername() == cur){
			(*i).isFriend(f);
			two = true;
		}
	}

	if (one == true && two == true){
		return true;
	}
	else{
		return false;
	}
}


#endif /* USERLIST_CPP_ */
