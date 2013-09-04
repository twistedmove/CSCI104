// Rewrite the central loop using recursion instead of a loop
// Measure how long the processing of the loop takes with both methods (for loop and recursion).
	// Do not include the time to read the input.
// Infer roughly how much overhead you get from recursion compared to loops (as a percentage).	

// Average: 2.9e-05

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
	int m; // we'll use this for the maximum number

	vector<int> numbers;
	string temp;

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

	// Time starts after importfile closes as designed
	clock_t timeStart;
	clock_t timeEnd;
	timeStart = clock();

	// stream-lined way of obtaining size without iterating twice. approved in lab
	n = numbers.size();

	// dynamically created a new int size of n
	a = new int[n];

	for (int i=0; i<n; i++){
		a[i] = numbers[i];
	}

	// the next part is the loop you are supposed to replace by recursion.
	m = a[0];
//	cout << m << endl;

	for (int i = 1; i < n; i ++)
		if (a[i] > m) 
			m = a[i]; // This is the end of the loop.
		
	cout << "The biggest number in the list is " << m << "." << endl;
	
	timeEnd = clock();
	cout << "It took " << (double)(timeEnd - timeStart)/CLOCKS_PER_SEC << " seconds to execute." << endl;

	delete[] a;
	a = NULL;

	return 0;
}