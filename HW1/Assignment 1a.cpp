#include <iostream>
using namespace std;

int main (void){
	int *a;
	int n; // number of elements in the array a
	int sum; // we'll use this for adding numbers

	/* here goes code to read n numbers into a, probably from a file
	Make sure to allocate space to a
	*/

	// the next part is the loop you are supposed to replace by recursion.
	sum = 0;
	
	for (int i = 0; i < n; i ++)
		sum += a[i]; // This is the end of the loop.
		cout << sum << endl;
		return 0;
	}