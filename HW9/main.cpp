/*
 * main.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: BryanChong
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "quicksort.h"
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

string fixString(string a){
	for (unsigned int i = 0; i < a.length(); i++){
		if (a[i] == ' '){
			a.erase(i,1);
		}
	}
	std::transform(a.begin(), a.end(), a.begin(), ::tolower);
	return a;
}


void importString(vector<string> &stringList, int &size){
	ifstream importFile("string.txt");
	if (importFile.fail()){
		cout << "<!-- string.txt does not exist. --!>" << endl;
	}

	string tsize;
	string temp;

	if (!is_Empty(importFile)){
		if (importFile.good()){
			getline(importFile, tsize, '\n');
			while(!importFile.eof()){
				getline(importFile, temp, '\n');
				temp = fixString(temp);
				stringList.push_back(temp);
			}
		}
	}

	size = atoi(tsize.c_str());

	importFile.close();
}

void importInt(vector<int> &intList,int &size, int &sum){
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

			while(!importFile.eof()){
				importFile >> temp;
				tempint = atoi(temp.c_str());
				intList.push_back(tempint);
			}
		}
	}

	size = atoi(tsize.c_str());
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
				vector<string> stringList;
				int size;

				importString(stringList, size);
				qSort<string> sorting;
				sorting.quickSort(stringList,size, 0, size-1);

				menu();
				break;
			}
			case 2:
			{
				int size;
				int sum;

				vector<int> intList;
				importInt(intList, size, sum);
				qSort<int> sorting;
				sorting.quickSort(intList,size, 0, size-1);

				for (int i = 0; i<intList.size(); i++){
					cout << intList[i] << endl;
				}


				menu();
				break;
			}
			case 3:
			{

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

