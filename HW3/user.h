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
		void setUsername(std::string usern);
		std::string returnUsername();
	private:
		std::string username;
		std::string password;
		std::string address;
		std::string email;
		Wall *UserWall;


};


#endif /* USER_H_ */
