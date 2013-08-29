// Rewrite the central loop using recursion instead of a loop
// Measure how long the processing of the loop takes with both methods (for loop and recursion).
	// Do not include the time to read the input.
// Infer roughly how much overhead you get from recursion compared to loops (as a percentage).	

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

int main (void){
	int *a;
	int n; // number of elements in the array a
	int m; // we'll use this for the maximum

	vector<int> numbers;
	string temp;
	/* here goes code to read n numbers into a, probably from a file
	Make sure to allocate space to a */
	string fileName;
	string temphold;
	cout << "Please type in the file name and extension to import." << endl;
	cin >> fileName;
	ifstream importFile(fileName.c_str());
	if (importFile.good()){
		while (importFile.good()){
			getline(importFile, temphold);
			stringstream ss(temphold);
			int integer;
			ss >> integer;
			numbers.push_back(integer);
		}
	}
	else if(importFile.fail()){
		cout << "Error: Check file name and location." << endl;
		return 0;
	}
	importFile.close();

	n = numbers.size();
	a = new int[n];

	
	// the next part is the loop you are supposed to replace by recursion.
	m = a[0];

	cout << m << endl;

	for (int i = 1; i < n; i ++)
		if (a[i] > m) m = a[i]; // This is the end of the loop.
			cout << m << endl;
		return 0;
}