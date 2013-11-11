/*
 * wallpost.h
 *
 *  Created on: Sep 20, 2013
 *      Author: BryanChong
 */

#ifndef WALLPOST_H_
#define WALLPOST_H_

#include <string>
#include "linklist.h"
#include "wallpostcomments.h"

class WallPost{
	public:
		WallPost();
		~WallPost();
		void setMessage(std::string message);
		void setAuthor(std::string author);
		void setID(int wallCounter);
		std::string getAuthor();
		std::string getMessage();
		int getID();

		void readWallPost();
		void editWallPost(std::string editedMessage);
		void printWallPost();

		std::string exportprintWallPost();

		void addComment(std::string, std::string);


	private:
		std::string wallmessage;
		std::string author;
		int id;
		LinkedList<WallPostComments*> *UserComments;
		int commentidCounter;
};


#endif /* WALLPOST_H_ */
