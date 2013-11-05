/*
 * student.h
 *
 *  Created on: Nov 4, 2013
 *      Author: bryanchong
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student{
	public:
		Student(std::string, int);
		void setName(std::string);
		void setID(int);
		std::string getName();
		int getID();

	private:
		std::string _name;
		int _id;
};


Student::Student(std::string name, int id){
	_id = id;
	_name = name;
}

void Student::setName(std::string name){
	_name = name;
}

void Student::setID(int id){
	_id = id;
}

int Student::getID(){
	return _id;
}

std::string Student::getName(){
	return _name;
}

#endif /* STUDENT_H_ */
