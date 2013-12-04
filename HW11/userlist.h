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
		void removeUser(User* todelete);
		void completeList();
		void removeFromFriend(std::string,std::string);

		void exportUserDatabase();
		void importUserDatabase();

		User* checkUser(std::string username);
		bool findUser(std::string, User*);
		bool validUser(std::string);
		bool is_Empty(std::ifstream&);
		bool checkifFriend(std::string, std::string);


		void displayUserWallPost(std::string);
		void commentFriendWallPost(std::string, std::string, std::string);
		void postFriendWall(std::string, std::string, std::string);
		void deleteFriendPost(std::string, std::string, std::string);
		void displayFriendsFriend(std::string);
		std::string fixString(std::string);
		void deleteCommentonFriendWall(std::string, std::string, std::string, std::string);


	private:
		 LinkedList<User> *UserLinkList;
};


#endif /* USERLIST_H_ */
