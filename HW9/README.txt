#2
	Runtime:
		The take for alpha to be within 0 < alpha < 1/2 would be a runtime of O(nlog base alpha of n). The recurrence formula of quicksort for median or best case time was T(n) = n + 2T(N/2) since T(N/2) represented the pivot being the median of the set. In the case where the pivot always divided the number of the set into equal parts (let's say for this example 1/3)), then T(N) = n + T(n-1 / 3)floor function + T(n-1 /3 ) ceiling function or simply put T(N) = N+T(N/3)+T(N/3). Which would equal to O(nlog3n), and the master theorem shows us this.

		Base case: n = T(1) = 1/3 ceiling function = 1
		Recursive case: T(N) = T(N/3) + n
		T(N) = T(N/3) + n
			 = 3(T(N/3) + T(N/6)) + n
			 = 6(T(N/6) + n) + n
			 ...
			 = n T(N/3^n) + T(N/3^n-1) + ... : T(N/3^n) -> T(1)
			 = n log base 3 n


#3
	String Problem:
		The quickest way that I thought of to solve this problem of finding is to first sort the array according to the alphabetic order. I used quicksort with a run time of O(nlog n). Then with the sorted array, I would create a counter and run through the sorted array, counting the number of similar strings and then +1 the counter if it is found. Otherwise, I would have a temp variable which would hold the next value which would also have its own seperate counter. I would then compare the two counters and then store the one that has the biggest counter. The runtime for this is n. The importing takes a run of O(n).
		Therefore the worst case run time analysis shows us a runtime of all the functionality together to be n(logn + 1 + 1..) which ends up being O(nlogn).

#4
	Number Problem:
		The best way I thought this would be would to once again sort the array using quicksort, which would end upw ith nlogn. Next I would have the program run through each index of the array and then set a temporary value that would be equal to the (sum you're trying to find - value at the index of array). Then using binary search, I would search for the temporary value which added with the index would equal to the sum. The iteration part takes a runtime of O(n) and the binary search takes a runtime of O(logn). Therefore the total runtime of this algorithm would be O(n*logn + n + ..) which is n(logn + 1..) which is equal to an algorithmic runtime of O(nlogn).


#5
		So.. I talked with some TAs and this part seems a bit non-sensical giving a problem where we aren't allowed to use pointers and only shift and do crazy things. I'm fully aware how a tree works but I don't think this part is completely allowing us to test our knowledge of a 2-3 tree. I thought of more creative way to approach it but it doesn't seem to be working, or my logic is completely off. I saved you time from errors, so PLEASE TAKE SOME TIME TO LOOK AT MY CODE AND COMMENT ON HOW I WOULD GO ABOUT DOING THIS IN THE FUTURE IF I EVER COME BACK. THANK YOU!