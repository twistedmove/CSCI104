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
	outputFile.open("database.txt");
	string outp;
	outputFile << '\n';

	outputFile << "Stephen`PASSWORD`1234 Example Rd.`stephen@usc.edu";
	outputFile << '\n';
	outputFile << "0`Stephen`This is Stephen's first wallpost.`1383314249|";
	outputFile << '\n';
	outputFile << "Tina1|";
	outputFile << '\n';
	outputFile << '\n';
	outputFile << '~';

	for (int i =0; i<90; i++){
		string t;
		string tt;
		string r;
		int ra;


		outp += '\n';
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
		outp += "Tina";
		tt = intToString(i+1);
		outp += tt;
		outp += "|";
		outp += '\n';
		outp += '\n';
		outp += "~";
	}
	for (int i =91; i<9999; i++){
		string t;
		string tt;
		string r;
		int ra;


		outp += '\n';
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
	}

	//cout << outp;
	outputFile << outp;

	outputFile.close();
	return 0;
}