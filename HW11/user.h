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
		void editInformation(std::string, std::string, std::string);
		Wall* getWall();

		void importWall(std::string array[]);
		void importWallComments(std::string array[], int);
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
		void setpoints(int);
		void setfriendlist(std::string);
		void setpendinglist(std::string);
		int getpoints();
		std::string getusername();
		std::string getaddress();
		std::string getemail();
		std::string getpassword();
		std::string getfriendlist();
		std::string getpendinglist();


		void displayPendingFriends();
		void displayFriends();
		void searchUser(std::string);

		void addFriend(User*);
		void addPendingFriend(User*);
		void acceptFriendRequest(std::string);
		void removePendingRequest();
		bool removeFriend(std::string);
		void removeUserFromFriendList(std::string);
		bool pendingEmpty();
		bool isFriend(std::string);

		void exportComments(std::ofstream *);





	private:
		std::string username;
		std::string password;
		std::string address;
		std::string email;
		int points;

		Wall *UserWall;
		LinkedList<User*> *Friends;
		LinkedList<User*> *PendingFriends;

		std::string friendlist;
		std::string pendinglist;


};


#endif /* USER_H_ */
