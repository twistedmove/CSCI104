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

		void importWall(std::string[]);
		void importFriends(User*);
		void importPendingFriends(User*);
		void exportWall(std::ofstream *);
		void exportFriendList(std::ofstream *);
		void exportPendingList(std::ofstream *);
		std::string exportprintUser();

		void setusername(std::string);
		void setpassword(std::string);
		void setaddress(std::string);
		void setemail(std::string);
		void setfriendlist(std::string);
		void setpendinglist(std::string);
		std::string getusername();
		std::string getfriendlist();
		std::string getpendinglist();

		void displayPendingFriends();
		void displayFriends();
		void searchUser(std::string);

		void addFriend(User*);
		void addPendingFriend(User*);
		void acceptFriendRequest();
		void removePendingRequest();
		void removeFriend();
		bool pendingEmpty();


	private:
		std::string username;
		std::string password;
		std::string address;
		std::string email;

		Wall *UserWall;
		LinkedList<User*> *Friends;
		LinkedList<User*> *PendingFriends;

		std::string friendlist;
		std::string pendinglist;


};


#endif /* USER_H_ */
