/*
 * main.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: BryanChong
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "quicksort.h"
#include "tree.h"
#include "node.h"
#include <limits>
using namespace std;

void menu(){
	cout << "               Menu              " << endl;
	cout << "*-------------------------------*" << endl;
	cout << "| 1. Frequent string test.      |" << endl;
	cout << "| 2. Adding numbers test.       |" << endl;
	cout << "| 3. Tree test. (GPA)           |" << endl;
	cout << "| 4. Quit the program           |" << endl;
	cout << "*-------------------------------*" << endl;
}

bool is_Empty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

string compare(string array[], int size){
	string previous = array[0];
	string frequent = array[0];
	int counter = 1;
	int freqcounter = 1;


	for (int i = 1; i < size; i++){
		if (array[i] == previous){
			counter++;
		}
		else {
			if (counter > freqcounter){
				frequent = array[i-1];
				freqcounter = counter;
			}
			previous = array[i];
			counter = 1;
		}
	}

	return frequent;
}

int binarySearch(int array[], int first, int last, int value){
	if (last < first){
		return std::numeric_limits<int>::max();
	}
	int middle = (first+last)/2;
	if (value < array[middle]){
		return binarySearch(array, first, middle-1, value);
	}
	else if (value > array[middle]){
		return binarySearch(array, middle+1, last, value);
	}
	else if (value == array[middle]){
		return array[middle];
	}
	else{
		return std::numeric_limits<int>::max();
	}
}

void findSum(int array[], int size, int sum){
	int temp = 0;
	int value = 0;
	int cur = 0;
	int first = 0;
	int last = size;



	for (int i = 0; i< size; i++){
		cur = array[i];
		temp = sum - array[i];
		value = binarySearch(array, first, last, temp);
		if (value != std::numeric_limits<int>::max()){
			cout << "Found!" << endl;
			cout << "     Value 1: " << cur << endl;
			cout << "     Value 2: " << value << endl;
			cout << "     Sum: " << cur+value << endl;
			break;
		}
	}
	if (value == std::numeric_limits<int>::max()){
		cout << "No addition of two sums found." << endl;
	}
}


int getSizefromFile(string fileName){
	string strsize;
	int intsize;

	ifstream importFile(fileName);
	if (importFile.fail()){
		cout << "<!-- Textfile does not exist. --!>" << endl;
	}
	if (!is_Empty(importFile)){
		if (importFile.good()){
			importFile >> strsize;
		}
	}
	intsize = atoi(strsize.c_str());

	return intsize;
}

string fixString(string a){
	for (unsigned int i = 0; i < a.length(); i++){
		if (a[i] == ' '){
			a.erase(i,1);
		}
	}
	std::transform(a.begin(), a.end(), a.begin(), ::tolower);
	return a;
}


void importString(string st[], int size){

	ifstream importFile("string.txt");
	if (importFile.fail()){
		cout << "<!-- string.txt does not exist. --!>" << endl;
	}

	string tsize;
	string temp;

	if (!is_Empty(importFile)){
		if (importFile.good()){
			getline(importFile, tsize, '\n');
			if(!importFile.eof()){
				for (int i=0; i<size; i++){
					getline(importFile, temp, '\n');
					temp = fixString(temp);
					st[i] = temp;
				}
			}
		}
	}


	importFile.close();
}

void importInt(int it[], int size, int &sum){


	ifstream importFile("number.txt");
	if (importFile.fail()){
		cout << "<!-- number.txt does not exist. --!>" << endl;
	}

	string tsize;
	string tsum;
	string junk;
	string temp;
	int tempint = 0;

	if (!is_Empty(importFile)){
		if (importFile.good()){
			importFile >> tsize;
			importFile >> tsum;
			if(!importFile.eof()){
				for (int i=0; i<size; i++){
					importFile >> temp;
					tempint = atoi(temp.c_str());
					it[i] = tempint;
				}
			}
		}
	}

	sum = atoi(tsum.c_str());
	importFile.close();
}


int main(){
	int selection = 0;
	menu();
	while (selection != 4){
		cout << "Selection: ";
		cin >> selection;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid Selection." << endl;
			continue;
		}
		cin.clear();
		cin.ignore(1024,'\n');

		cout << endl;
		switch (selection)
		{
			case 1:
			{
				string popular;
				string fileName = "string.txt";
				int size = getSizefromFile(fileName);
				string *stringList = new string[size];

				importString(stringList, size);

				qSort<string> sorting;
				sorting.quickSort(stringList,0,size-1);

				popular = compare(stringList, size);

				cout << "Most frequent string is: " << popular << endl;
				menu();
				break;
			}
			case 2:
			{
				int sum;
				string fileName = "number.txt";

				int size = getSizefromFile(fileName);
				int *intList = new int[size];
				importInt(intList, size, sum);

				qSort<int> sorting;
				sorting.quickSort(intList, 0, size-1);

				findSum(intList, size, sum);


				menu();
				break;
			}
			case 3:
			{
				int id;
				float gpa;

				cout << "Please insert the student id." << endl;
				cin >> id;
				cout << "Please enter the student's GPA, out of 4.0." << endl;
				cin >> gpa;
				TwoThreeTree<int, float> tree(id, gpa);
			//	tree.print();
				cout << "Read README.txt and source code." << endl;

				menu();
				break;
			}
			case 4:
			{
				cout << "<!-- PROGRAM TERMINATED --!>" << endl;
				break;
			}
			default:
			{
				cout << "<!-- INVALID SELECTION --!>" << endl;
			}

		}
	}





	return 0;
}

