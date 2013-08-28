// Rewrite the central loop using recursion instead of a loop
// Measure how long the processing of the loop takes with both methods (for loop and recursion).
	// Do not include the time to read the input.
// Infer roughly how much overhead you get from recursion compared to loops (as a percentage).	

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int main (void){
	int *a;
	int n; // number of elements in the array a
	int m; // we'll use this for the maximum

	/* here goes code to read n numbers into a, probably from a file
	Make sure to allocate space to a */
	
	// the next part is the loop you are supposed to replace by recursion.
	m = a[0];

	for (int i = 1; i < n; i ++)
		if (a[i] > m) m = a[i]; // This is the end of the loop.
			cout << m << endl;
		return 0;
}