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
//	UserLinkList->SetIteratorBegin();
	std::ofstream *exportFile = new std::ofstream;
	exportFile->open("database.txt");

/*
	for (int i = 0; i < UserLinkList->size(); i++) {
		std::string tempholder;
		tempholder = UserLinkList->IteratorValue().exportprintUser();
		*(exportFile) << tempholder;
		*(exportFile) << "\n";
		UserLinkList->IteratorValue().exportWall(exportFile);
		*(exportFile) << "\n";
		UserLinkList->IncrementIterator();
	}
*/

	if (UserLinkList->size() != 0){
		for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
			if((*i).getUser() != ""){
				std::string tempholder;
				tempholder = (*i).exportprintUser();
				*(exportFile) << tempholder;
				*(exportFile) << "\n";
				(*i).exportWall(exportFile);
				*(exportFile) << "\n";
				(*i).exportFriendList(exportFile);
				*(exportFile) << "\n";
				(*i).exportPendingList(exportFile);
				*(exportFile) << "\n";
			}
			if ((*i).getUser() == ""){
				UserLinkList->decSize();
			}
		}
		std::cout << UserLinkList->size() << std::endl;
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
	if (!is_Empty(importFile)){
	if (importFile.good()){
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

 			std::getline(importFile, temporary, '\n');

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



/*
// Third line - parses through all the friends list
			position = 0;
			std::getline(importFile, temporary, '\n');

			while ((position = temporary.find(postdelimiter)) !=  std::string::npos){
					std::string friendinformationarray[4];
					int friendcounter = 0;
					tempfriend = temporary.substr(0, position);
			// std::cout << tempfriend << std::endl;
					unsigned long int newpos = 0;
				while ((newpos = tempfriend.find(delimiter)) !=  std::string::npos){
					tempitem = tempfriend.substr(0, newpos);
					std::cout << tempitem << std::endl;
					friendinformationarray[friendcounter] = tempitem;
					friendcounter++;
					temporary.erase(0, position + postdelimiter.length());
					newUser->importFriends(friendinformationarray);
				}
			}


// Fourth line - parses through all the pending friends list
			position = 0;
			std::getline(importFile, temporary, '\n');

			while ((position = temporary.find(postdelimiter)) !=  std::string::npos){
					std::cout << position << std::endl;
					std::string pendinginformationarray[4];
					int pendingcounter = 0;
					temppending = temporary.substr(0, position);
					std::cout << temppending << std::endl;
					unsigned long int newpos = 0;
				while ((newpos = temppending.find(delimiter)) !=  std::string::npos){
					std::cout << temppending[newpos] << std::endl;
					std::cout << temppending[newpos+1] << std::endl;
			//		std::cout << "1" << std::endl;
					tempitem = temppending.substr(0, newpos);
					std::cout << tempitem << std::endl;
					pendinginformationarray[pendingcounter] = tempitem;		//problem here
					pendingcounter++;
					temporary.erase(0, position + postdelimiter.length());
					newUser->importPendingFriends(pendinginformationarray);
			//		std::cout << "before end" << std::endl;
				}
				std::cout << "outside inner while" << std::endl;
			}	// end of "fourth line code" while loop
			std::cout << "outside while" << std::endl;

*/
		} 		// while !importfile.eof
	} 			// end of if importfile.good();
	}
	importFile.close();
}				// end of importUserDatabase function

void UserList::addUser(User& u){
	std::cout << "Please create your new credentials." << std::endl;
	u.editInformation();
	UserLinkList->push_back(u);
}

void UserList::deleteUser(User& u){
	UserLinkList->removeObject(u);
}

User* UserList::checkUser(std::string username){
/*
	UserLinkList->SetIteratorBegin();
		for (int i = 0; i < UserLinkList->size(); i++) {
			if (username == UserLinkList->IteratorValue().returnUsername()) {
				return &(UserLinkList->IteratorValue());
			}
			UserLinkList->IncrementIterator();
		}
*/


	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if (username == (*i).returnUsername()){
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
//	int inputfriend;
	LinkedList<User> searchResults;

	bool found = false;
	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		tempuser = (*i).returnUsername();
		if (tempuser.find(findusername) != std::string::npos){

			searchResults.push_back(*i);
			std::cout << counter << ": " << tempuser << std::endl;
			counter++;
			found = true;
		}
	}


/*
	std::cout << "Please select the number would you like to be friends with?" << std::endl;
	std::cout << "Please press -1 to cancel." << std::endl;
	std::cin >> inputfriend;

	if(inputfriend < searchResults.size()){
		if (inputfriend == -1){
			std::cout << "Action canceled." << std::endl;
		}
		else{
			try{
				currentUser->addFriend(&(searchResults.find(inputfriend)));
			}catch(std::invalid_argument & e){
				e.what();
			}
		}
	}
*/

	return found;
}

bool UserList::validUser(std::string usercheck){
	for (Iterator<User> i = UserLinkList->begin(); i != UserLinkList->end(); ++i){
		if (usercheck == (*i).returnUsername()){
			return true;
		}
	}
	return false;

}


std::string UserList::fixString(std::string u){
	std::string s = u;
	// remove whitespace
		for (int unsigned i=0; i<s.length(); i++){
	//		cout << s[i] << endl;
			if (s[i] == ' '){
				s.erase(i,1);
			}
		}
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		return s;
}

#endif /* USERLIST_CPP_ */
