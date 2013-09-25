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


class User{
	public:
		User();
		~User();
		void addWallPost();
		void removeWallPost();
		void printInformation();
		void editInformation();
	private:
		std::string username;
		std::string password;
		std::string address;


};


#endif /* USER_H_ */
