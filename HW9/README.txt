#3
	String Problem:
		The quickest way that I thought of to solve this problem of finding is to first sort the array according to the alphabetic order. I used quicksort with a run time of O(nlog n). Then with the sorted array, I would create a counter and run through the sorted array, counting the number of similar strings and then +1 the counter if it is found. Otherwise, I would have a temp variable which would hold the next value which would also have its own seperate counter. I would then compare the two counters and then store the one that has the biggest counter. The runtime for this is n. The importing takes a run of O(n).
		Therefore the worst case run time analysis shows us a runtime of all the functionality together to be n(logn + 1 + 1..) which ends up being O(nlogn).

#4
	Number Problem:
		The best way I thought this would be would to once again sort the array using quicksort, which would end upw ith nlogn. Next I would have the program run through each index of the array and then set a temporary value that would be equal to the (sum you're trying to find - value at the index of array). Then using binary search, I would search for the temporary value which added with the index would equal to the sum. The iteration part takes a runtime of O(n) and the binary search takes a runtime of O(logn). Therefore the total runtime of this algorithm would be O(n*logn + n + ..) which is n(logn + 1..) which is equal to an algorithmic runtime of O(nlogn).


