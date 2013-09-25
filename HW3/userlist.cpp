/*
 * userlist.hpp
 *
 *  Created on: Sep 24, 2013
 *      Author: BryanChong
 */

#ifndef USERLIST_HPP_
#define USERLIST_HPP_

#include "userlist.h"
#include "user.h"
#include "linklist.h"
#include <iostream>


UserList::UserList(){
	UserLinkList = new LinkedList<User>;
}

UserList::~UserList(){
	delete UserLinkList;
}

void UserList::printUserDatabase(){

}

void UserList::importUserDatabase(std::string s){

}

void UserList::addUser(User& u){
	std::cout << "Please create your new credentials." << std::endl;
	u.editInformation();
	UserLinkList->push_back(u);
}

void UserList::deleteUser(User& u){
	UserLinkList->pop_back();
}

#endif /* USERLIST_HPP_ */
