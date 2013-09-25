/*
 * user.hpp
 *
 *  Created on: Sep 24, 2013
 *      Author: BryanChong
 */

#ifndef USER_HPP_
#define USER_HPP_

#include "user.h"
#include <iostream>

User::User(){
}

User::~User(){

}

void User::addWallPost(){

}

void User::printInformation(){

}

void User::removeWallPost(){

}

void User::editInformation(){
	std::cout << "What is your username?" << std::endl;
	std::cin >> username;
	std::cout << "What is your password?" << std::endl;
	std::cin >> password;
	std::cout << "What is your address?" << std::endl;
	std::cin >> address;

}



#endif /* USER_HPP_ */
