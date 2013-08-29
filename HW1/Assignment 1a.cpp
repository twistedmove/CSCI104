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

int recursion(int *array, int size, int total, int counter){
	if (size == 0){
		return total; // should be zero since nothing in array
	} else if (counter == size){
		cout << total << endl;
		return total;
	} else{
		total += array[counter];
		counter++;
		recursion(array, size, total, counter);
	}
}

int main (void){
	int *a; // initialized pointer a
	int n; // number of elements in the array a
	int sum; // we'll use this for adding numbers

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

	for (int i=0; i<n; i++){
		a[i] = numbers[i];
	}

	// the next part is the loop you are supposed to replace by recursion.
	sum = 0;
	int counter = 0;
	

	recursion(a, n, sum, counter); 
	return 0;


/*
	for (int i = 0; i < n; i ++)
		sum += a[i]; // This is the end of the loop.
		cout << sum << endl;
	return 0;
*/
}
