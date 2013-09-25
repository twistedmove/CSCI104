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

class UserList{
	public:
		UserList();
		~UserList();
		void addUser(User&);
		void deleteUser(User&);
		void printUserDatabase();
		void importUserDatabase(std::string);
	private:
		 LinkedList<User> *UserLinkList;
};


#endif /* USERLIST_H_ */
