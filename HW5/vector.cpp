/*
 * vector.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: BryanChong
 */


#include <iostream>
#include <sstream>
#include <istream>
#include "vector.h"
#include "linkedlist.h"
#include <string>

mathVector::mathVector(){
	size = 1;
	mathList = new double[1];
}

mathVector::mathVector(const mathVector& copy){
	size = copy.size;
	mathList = new double[size];
	for (int i = 0; i < size; i++){
		this->mathList[i] = copy.mathList[i];
	}
}

mathVector::mathVector(double number){
	mathList = new double[1];
	mathList[0] = number;
	size = 1;
}

mathVector::mathVector(std::string inputstring){
	std::string tempstring = inputstring;

	double tempnum;
	std::stringstream ss(tempstring);

	while (!ss.eof()){
		std::string numbercounter;
		getline(ss, numbercounter, ',');
		size++;
	}

	mathList = new double[size];

	std::stringstream st(tempstring);
	st.get();
	for (int i=0; i<size; i++){
		st >> tempnum;
		mathList[i] = tempnum;
		st.get();
	}

}


mathVector::~mathVector(){
	delete mathList;
}


std::string mathVector::toString(){
	std::stringstream ss;
	ss << "[";
	for (int i = 0; i < size-1; i++){
		ss << this->mathList[i];
		ss << ",";
	}
	ss << this->mathList[size-1];
	ss << "]";

	std::string outputstr = ss.str();

	return outputstr;
}

mathVector& mathVector::operator+(const mathVector& other){
	if (other.size != this->size){
		throw std::invalid_argument("vector.cpp:82 Size of two vectors is not equal.");
	}
	double *temparray = new double[size];
	for (int i =0; i<size; i++){
		temparray[i] = other.mathList[i] + this->mathList[i];
	}
	mathVector *newVector = new mathVector;

	newVector->size = this->size;
	newVector->mathList = temparray;


	return *newVector;
}

mathVector& mathVector::operator-(const mathVector& other){
	if (other.size != this->size){
		throw std::invalid_argument("vector.cpp:99 Size of two vectors is not equal.");
	}
	double *temparray = new double[size];
	for (int i =0; i<size; i++){
		temparray[i] = other.mathList[i] - this->mathList[i];
	}
	mathVector *newVector = new mathVector;

	newVector->size = this->size;
	newVector->mathList = temparray;


	return *newVector;
}


mathVector& mathVector::operator*(const mathVector& other){
	mathVector *newVector = new mathVector;
	double temporaryarr[3];
	if (other.size == 1 && this->size > 1){
		double *temparray = new double[this->size];
		for (int i = 0; i < this->size; i++){
			temparray[i] = other.mathList[0]*this->mathList[i];
		}
		mathVector *newVector = new mathVector;
		newVector->size = this->size;
		newVector->mathList = temparray;
		return *newVector;
	}
	else if (this->size == 1 && other.size > 1){
		double *temparray = new double[other.size];
		for (int j = 0; j < other.size; j++){
			temparray[j] = other.mathList[j] * this->mathList[0];
		}
		mathVector *newVector = new mathVector;
		newVector->size = other.size;
		newVector->mathList = temparray;
		return *newVector;
	}
	else if (other.size == 1 && this->size == 1){
		double *temparray = new double[1];
		temparray[0] = other.mathList[0] * this->mathList[0];
		mathVector *newVector = new mathVector;
		newVector->size = 1;
		newVector->mathList = temparray;
		return *newVector;
	}
	else if(other.size == 3 && this->size == 3){
		temporaryarr[0] = other.mathList[0] * this->mathList[0];
		temporaryarr[1] = other.mathList[0] * this->mathList[1];
		temporaryarr[2] = other.mathList[0] * this->mathList[2];
		double *temparray = new double[1];
		temparray[0] = temporaryarr[0] + temporaryarr[1] + temporaryarr[2];
		mathVector *newVector = new mathVector;
		newVector->size = 1;
		newVector->mathList = temparray;
		return *newVector;
	}

	return *newVector;
}


double mathVector::operator[](const int loc){
	if (loc < 0 || loc >= size){
		throw std::out_of_range("Out of range.");
	}
	return this->mathList[loc];
}

bool mathVector::operator!=(const mathVector& other){
	if (other.size != this->size){
		throw std::invalid_argument("vector.cpp:171 Size of two vectors is not equal.");
	}
	for (int i =0; i<size; i++){
		if (other.mathList[i] != this->mathList[i]){
			return true;
		}
	}
	return false;
}


bool mathVector::operator==(const mathVector& other){
	if (other.size != this->size){
		throw std::invalid_argument("vector.cpp:184 Size of two vectors is not equal.");
	}
	for (int i =0; i<size; i++){
		if (other.mathList[i] != this->mathList[i]){
			return false;
		}
	}
	return true;
}

void mathVector::operator=(const mathVector& other){
	if (other.size != this->size){
		throw std::invalid_argument("vector.cpp:196 Size of two vectors is not equal.");
	}
	for (int i =0; i<size; i++){
		this->mathList[i] = other.mathList[i];
	}
}

int mathVector::getSize(){
	return size;
}
