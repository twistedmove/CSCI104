// Rewrite the central loop using recursion instead of a loop
// Measure how long the processing of the loop takes with both methods (for loop and recursion).
	// Do not include the time to read the input.
// Infer roughly how much overhead you get from recursion compared to loops (as a percentage).	

// Average: 2.5e-05

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;


int main (void){
	int *a; // initialized pointer a
	int n; // number of elements in the array a
	int sum; // we'll use this for adding numbers

	// vector<int> numbers;

	// please note that that first number in numbers.txt defines the size of the array (and was suggested by prof kempe)
	// i had to change it from vector based to the suggested solution above
	// commented code is from the use of vector methods

	string temp;
	string fileName;
	string temphold;
	int counter = 0;
	cout << "Please type in the file name and extension to import. (numbers.txt)" << endl;
	cin >> fileName;
	ifstream importFile(fileName.c_str());
	if (importFile.good()){
			string temp;
			getline(importFile, temp);
			stringstream ss(temp);
			ss >> n;
			a = new int[n];
		while (importFile.good()){
			getline(importFile, temphold);
			stringstream ss(temphold);
			int integer;
			ss >> integer;
			a[counter] = integer;
			counter++;
			// numbers.push_back(integer);
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
	// n = numbers.size();
	// dynamically created a new int size of n
	// a = new int[n];

	// for (int i=0; i<n; i++){
	//	a[i] = numbers[i];
	// }

	// Using loop to add up the numbers in the array
	sum = 0;
	
	for (int i = 0; i < n; i ++)
		sum += a[i]; // This is the end of the loop.
		cout << "The sum of all numbers is: " << sum << endl;

	timeEnd = clock();
	cout << "It took " << (double)(timeEnd - timeStart)/CLOCKS_PER_SEC << " seconds to execute." << endl;

	delete[] a;
	a = NULL;

	return 0;
}
