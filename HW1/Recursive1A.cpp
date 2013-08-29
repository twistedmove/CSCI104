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

	clock_t timeStart;
	clock_t timeEnd;
	timeStart = clock();


	n = numbers.size();

	a = new int[n];

	for (int i=0; i<n; i++){
		a[i] = numbers[i];
	}

	// the next part is the loop you are supposed to replace by recursion.
	sum = 0;
	int counter = 0;

	int total = recursion(a, n, sum, counter);
	cout << "The sum of all numbers is: " << total << endl; 

	timeEnd = clock();
	cout << "It took " << (double)(timeEnd - timeStart)/CLOCKS_PER_SEC << " seconds to execute." << endl;

	return 0;


/*
	for (int i = 0; i < n; i ++)
		sum += a[i]; // This is the end of the loop.
		cout << sum << endl;
	return 0;
*/

}
