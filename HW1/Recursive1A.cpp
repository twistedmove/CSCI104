// Rewrite the central loop using recursion instead of a loop
// Measure how long the processing of the loop takes with both methods (for loop and recursion).
	// Do not include the time to read the input.
// Infer roughly how much overhead you get from recursion compared to loops (as a percentage).	

// Average: 4.4e-05

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

int recursion(int *array, int size, int total, int counter){
	int returnVal = 0;

	if (size == 0){
		return total; // should be zero since nothing in array

	} else if (counter == size){
		return total;
	} else{
		total += array[counter];
		counter++;
		returnVal = recursion(array, size, total, counter);
		return returnVal;
	}
}

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
	int count;
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
			a[count] = integer;
			count++;
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

	// the next part is the loop you are supposed to replace by recursion.
	sum = 0;
	int counter = 0;

	int total = recursion(a, n, sum, counter);
	cout << "The sum of all numbers is: " << total << endl; 

	timeEnd = clock();
	cout << "It took " << (double)(timeEnd - timeStart)/CLOCKS_PER_SEC << " seconds to execute." << endl;

	delete[] a;
	a = NULL;

	return 0;
}
