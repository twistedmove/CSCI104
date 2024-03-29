Didn't finish part (e). Worked on it partially to save you time why some things might not work!

HOMEWORK 7 QUESTIONS:

(a) Precisely state the Heap Property for complete d-ary trees.
(i) For a min-heap, the priority is at least as large as the parent while in a max-heap the priority is no bigger than the parent's priority.


(b) One of the advantages of using complete binary trees was that it made it easy to store the tree in an array and do simple calculations to find the index of the parent and the children of a given node i. 
Give formulas for calculating the parent and the children when the tree is d-ary. (Specify clearly whether the root of your tree is in array index 0 or 1; you can make it work either way, but you should let us know which one you do.)
(i) Index root is 0. The floor function of the (index - 1)/d is the parent of the children. The children of the parent would be (k*d)+1 where k is the current node we're on. To easily check it, if you have the parent function in the child function, it should equal to the node of the current.


(c) As we saw in class, the advantage of a complete binary tree was that the height is log2(n), which means that insertions and deletions run in O(log n). What is the height of a complete d-ary tree with n nodes? Show us the calculations that arrive at your answer.
(i) The sum from i=0 to k of d^i where i is the level and d^i would be a completely filled level i, would equal to d^(k+1) - 1 / (d - 1) where k is the last completely filled level in the heap. Assuming the last element of the array is at position 'n', then the height = log of d (n(d - n + 1) - 1. This is obtained by citing the heap which is 1+d+d^2 (parent) + d^3 + ... + d^h, where h is the height. This is a simple geometric progression (learned from CSCI170) and is equal to log base d of (n*d) - 1 = log base d(n) + log base d - 1 which is equal to log base d of n.


(d) Based on your calculation of tree heights, analyze the running times of the natural generalizations of trickleUp and trickleDown to d-ary tree in big-O/omega/theta notation. Use this analysis to analyze the running times for add, remove, and peek.
Your running time will be a function of two variables, d and n. There is nothing magical about big-O notation only working for one variable -- you can use it with functions of many variables as well.
(i) Runtime of add and remove is theta(log base d of n); Peek takes theta(1) since it just takes the root.


(e) Based on your running time calculations, which operations get faster, and which get slower, as you increase d?
(i) Adding and removing gets faster as you increase d, however, peek doesn't change considering that it takes the root node. A larger base in a log function decreases the value of the run time speed, making it considerably faster as you increase d (or the number of trees).



Macintosh:HW7 bryanchong$ ./tree
Insertion took: 0.002082
Insertion took: 0.002065
Insertion took: 0.002081
Insertion took: 0.002096
Insertion took: 0.002132
Insertion took: 0.002053
Insertion took: 0.002054
Insertion took: 0.002066
Insertion took: 0.002079
Insertion took: 0.002069
Removal took: 0.149526
Removal took: 0.152266
Removal took: 0.151599
Removal took: 0.149956
Removal took: 0.150689
Removal took: 0.15282
Removal took: 0.156964
Removal took: 0.158092
Removal took: 0.155125
Removal took: 0.155416

Macintosh:HW7 bryanchong$ ./tree
Insertion took: 0.002131
Insertion took: 0.002116
Insertion took: 0.002119
Insertion took: 0.00211
Insertion took: 0.002159
Insertion took: 0.002235
Insertion took: 0.002123
Insertion took: 0.002166
Insertion took: 0.00222
Insertion took: 0.002167
Removal took: 0.15043
Removal took: 0.148127
Removal took: 0.149817
Removal took: 0.149968
Removal took: 0.154487
Removal took: 0.155426
Removal took: 0.15445
Removal took: 0.153973
Removal took: 0.155036
Removal took: 0.159602


I ran my program twice and it was ALMOST as how I described it above. The insertion didn't take as long, nor did the removal. Considering the increase in d, there were times where it got slightly faster as d increased. The runtime approximately took around the same amount of time which could be influenced by my machine and also the programs running in the background. It somewhat follows the trend of the theoretical analysis above.