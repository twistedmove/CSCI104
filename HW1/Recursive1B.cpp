// Rewrite the central loop using recursion instead of a loop
// Measure how long the processing of the loop takes with both methods (for loop and recursion).
	// Do not include the time to read the input.
// Infer roughly how much overhead you get from recursion compared to loops (as a percentage).	

// Average: 3.5e-05

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

// int swap(int *array, int counter){} // Swap function if you want to preserve the values in array

int recursive(int max, int *array, int size, int counter){
	int returnVal = 0;
	if (size == 0){
		return 0;
	} else if (size == 1){
		max = array[0];
		return max;
	} else if (counter == size){
//		cout << max << endl;
		return max;
	} else if (max < array[counter])
	//	swap(array, counter); // Swap to preserve array values otherwise just replace since only finding max
		max = array[counter];
		counter++;
		returnVal = recursive(max,array,size,counter);
		return returnVal;
}

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

	clock_t timeStart;
	clock_t timeEnd;
	timeStart = clock();

	n = numbers.size();
	a = new int[n];

	// Stored each element from the vector to the pre-defined n array.
	for (int i=0; i<n; i++){
		a[i] = numbers[i];
	}

	// the next part is the loop you are supposed to replace by recursion.
	m = a[0];
	int counter = 0;
	int biggest = recursive(m, a, n, counter);

	/*
	cout << m << endl;

	for (int i = 1; i < n; i ++)
		if (a[i] > m) 
			m = a[i]; // This is the end of the loop.
	*/

	cout << "The biggest number in the list is " << biggest << "." << endl;

	timeEnd = clock();
	cout << "It took " << (double)(timeEnd - timeStart)/CLOCKS_PER_SEC << " seconds to execute." << endl;


	return 0;
}