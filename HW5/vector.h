/*
 * vector.h
 *
 *  Created on: Oct 9, 2013
 *      Author: BryanChong
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <string>
#include "arraylist.h"

class mathVector{
	public:
		mathVector();
		mathVector(const mathVector&);
		mathVector(double number);
		mathVector(std::string);
		~mathVector();
		std::string toString();
		mathVector& operator+(const mathVector& other);
		mathVector& operator-(const mathVector& other);
		mathVector& operator*(const mathVector& other);
		bool operator!=(const mathVector& other);
		bool operator==(const mathVector& other);
		void operator=(const mathVector& other);
		double operator[](const int loc);
		int getSize();

	private:
		double *mathList;
		int size;

};



#endif /* VECTOR_H_ */
