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
#include "linklist.h"

class WallPostComments{
	public:
		WallPostComments();
		~WallPostComments();
		void setComment(std::string);
		void setAuthor(std::string);
		void setID(int wallCounter);
		void setTime(std::string);
		void setHour(std::string);
		void setMinute(std::string);
		void setSecond(std::string);

		std::string getAuthor();
		std::string getMessage();
		std::string getTime();
		std::string getHour();
		std::string getMinute();
		std::string getSecond();
		int getID();


		void readWallPostComments();
		void editWallPostComments(std::string editedMessage);
		void printWallPostComments();

		std::string exportprintWallPostComments();


	private:
		std::string comment;
		std::string author;
		std::string time;
		std::string hour;
		std::string minute;
		std::string second;
		int id;
};



#endif /* WALLPOSTCOMMENTS_H_ */
