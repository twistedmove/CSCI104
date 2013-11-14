#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <string>
using namespace std;

string intToString(int number){
	std::stringstream ss;
	ss << number;
	return ss.str();
}


int randomgen(){
	srand ( time(NULL) );

	int random = rand() % 1000000;;
	return random;
}


int main(){

	ofstream outputFile;
	outputFile.open("datab.txt");
	string outp;
	outputFile << '\n';

	for (int i =0; i<9999; i++){
		string t;
		string r;
		int ra;
		outp += "Tina";
		t = intToString(i);
		outp += t;
		outp += "`PASSWORD`1234 Example Rd.`tina@usc.edu";
		outp += '\n';
		outp += "0`Tina`This is Tina's first wallpost.`1383";
		ra = randomgen();
		r = intToString(ra);
		outp += r;
		outp += "|";
		outp += '\n';
		outp += "Stephen|";
		outp += '\n';
		outp += '\n';
		outp += "~";
		outp += '\n';
	}

	//cout << outp;
	outputFile << outp;

	outputFile.close();
	return 0;
}