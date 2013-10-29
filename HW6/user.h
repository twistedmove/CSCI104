/*
 * user.h
 *
 *  Created on: Sep 23, 2013
 *      Author: BryanChong
 */

#ifndef USER_H_
#define USER_H_

#include <cstdlib>
#include <string>
#include "wall.h"


class User{
	public:
		User();
		~User();
		void addWallPost(std::string wallmessage);
		void removeWallPost(int id);
		void printInformation();
		void editInformation();
		Wall* getWall();

		void exportWall(std::ofstream *);
		void importWall(std::string[]);
		void importFriends(std::string[]);
		void importPendingFriends(std::string[]);

		void setusername(std::string);


		std::string exportprintUser();
		void exportFriendList(std::ofstream *);
		void exportPendingList(std::ofstream *);
		std::string returnUsername();
		void setpassword(std::string);
		void setaddress(std::string);
		void setemail(std::string);

		void addFriend(User*);
		void addPendingFriend(User*);
		void displayPendingFriends();
		void searchUser(std::string);
		void displayFriends();
		void acceptFriendRequest();
		void removePendingRequest();
		void removeFriend();
		std::string getUser();
		bool pendingEmpty();
	private:
		std::string username;
		std::string password;
		std::string address;
		std::string email;
		Wall *UserWall;
		LinkedList<User*> *Friends;
		LinkedList<User*> *PendingFriends;


};


#endif /* USER_H_ */
