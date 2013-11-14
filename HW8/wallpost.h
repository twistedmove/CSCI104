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
		void setRawTime(std::string);
		void setRawTime(time_t);
		void setTime(std::string);

		std::string getAuthor();
		std::string getMessage();
		std::string getTime();
		int getID();
		time_t getRawTime();
		std::string intToString(int);

		void readWallPost();
		void editWallPost(std::string editedMessage);
		void printWallPost();

		std::string exportprintWallPost();
		void importCommentsfromString(std::string,std::string,std::string,std::string);
		void deleteCommentPost(int, std::string);

		void addComment(std::string, std::string);

		std::string exporttoString();


	private:
		std::string wallmessage;
		std::string author;
		int id;
		std::string wptime;
		time_t wprawtime;
		LinkedList<WallPostComments*> *UserComments;
		int commentidCounter;
};


#endif /* WALLPOST_H_ */
