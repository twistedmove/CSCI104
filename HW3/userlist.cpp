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


UserList::UserList(){
	UserLinkList = new LinkedList<User>;
}

UserList::~UserList(){
	delete UserLinkList;
}

void UserList::exportUserDatabase(){

}

void UserList::importUserDatabase(std::string s){

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
