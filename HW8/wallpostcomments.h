/*
 * wallpostcomments.h
 *
 *  Created on: Nov 10, 2013
 *      Author: BryanChong
 */

#ifndef WALLPOSTCOMMENTS_H_
#define WALLPOSTCOMMENTS_H_

#include <string>
#include <time.h>
#include <string>
#include "linklist.h"

class WallPostComments{
	public:
		WallPostComments();
		~WallPostComments();
		void setComment(std::string);
		void setAuthor(std::string);
		void setID(int wallCounter);
		void setTime(std::string);
		void setRawTime(time_t);

		std::string getAuthor();
		std::string getMessage();
		std::string getTime();
		time_t getRawTime();
		int getID();

		void readWallPostComments();
		void editWallPostComments(std::string editedMessage);
		void printWallPostComments();

		std::string exportprintWallPostComments();
		std::string intToString(int);

		void importTime(std::string);

	private:
		int id;
		std::string comment;
		std::string author;
		std::string time;
		time_t rawtime;

};



#endif /* WALLPOSTCOMMENTS_H_ */
