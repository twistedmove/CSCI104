(a) Precisely state the Heap Property for complete d-ary trees.
	For a min-heap, the priority is at least as large as the parent while in a max-heap the priority is no bigger than the parent's priority.


(b) One of the advantages of using complete binary trees was that it made it easy to store the tree in an array and do simple calculations to find the index of the parent and the children of a given node i. 
Give formulas for calculating the parent and the children when the tree is d-ary. (Specify clearly whether the root of your tree is in array index 0 or 1; you can make it work either way, but you should let us know which one you do.)
	Index root is 0. The floor function of the (index - 1)/d is the parent of the children.

(c) As we saw in class, the advantage of a complete binary tree was that the height is log2(n), which means that insertions and deletions run in O(log n). What is the height of a complete d-ary tree with n nodes? Show us the calculations that arrive at your answer.
	The sum from i=0 to k of d^i where i is the level and d^i would be a completely filled level i, would equal to d^(k+1) - 1 / (d - 1) where k is the last completely filled level in the heap. Assuming the last element of the array is at position 'n', then the height = log of d (n(d - n + 1) - 1.


(d) Based on your calculation of tree heights, analyze the running times of the natural generalizations of trickleUp and trickleDown to d-ary tree in big-O/omega/theta notation. Use this analysis to analyze the running times for add, remove, and peek.
Your running time will be a function of two variables, d and n. There is nothing magical about big-O notation only working for one variable -- you can use it with functions of many variables as well.
	Runtime of add and remove is theta(log base d of n); Peek takes theta(1).


(e) Based on your running time calculations, which operations get faster, and which get slower, as you increase d?
	Adding and removing gets faster as you increase d, however, peek doesn't change considering that it takes the root node. A larger base in a log function decreases the value of the run time speed, making it considerably faster as you increase d (or the number of trees).