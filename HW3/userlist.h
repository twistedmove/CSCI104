/*
 * userlist.h
 *
 *  Created on: Sep 23, 2013
 *      Author: BryanChong
 */

#ifndef USERLIST_H_
#define USERLIST_H_

#include <string>

#include "user.h"
#include "linklist.h"
#include "wall.h"

class UserList{
	public:
		UserList();
		~UserList();
		void addUser(User&);
		void deleteUser(User&);
		void printUserDatabase();
		void importUserDatabase(std::string);
		void removeUser(User* todelete);
		User* checkUser(std::string username);
	private:
		 LinkedList<User> *UserLinkList;
};


#endif /* USERLIST_H_ */
