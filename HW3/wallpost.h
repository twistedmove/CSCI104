/*
 * wallpost.h
 *
 *  Created on: Sep 20, 2013
 *      Author: BryanChong
 */

#ifndef WALLPOST_H_
#define WALLPOST_H_

#include <string>

class WallPost{
	public:
		WallPost();
		~WallPost();
		void setMessage(std::string message);
		void setAuthor(std::string author);
		void readWallPost();
		void setID(int wallCounter);
		int getID();
		std::string getAuthor();
		std::string getMessage();
		void editWallPost(std::string editedMessage);
		void printWallPost();
	private:
		std::string wallmessage;
		std::string author;
		int id;
};


#endif /* WALLPOST_H_ */
