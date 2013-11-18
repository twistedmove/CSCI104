/*
 * tree.h
 *
 *  Created on: Nov 15, 2013
 *      Author: BryanChong
 */

#ifndef TREE_H_
#define TREE_H_

#include <vector>

template <class KeyType, class ValueType>
class Node {
	public:
		int numberOfKeys;
		KeyType leftKey, rightKey;
		ValueType leftValue, rightValue;
		int leftChild, middleChild, rightChild;
		Node (const KeyType & key, const ValueType & value); // one key only
		Node (const KeyType & lKey, const ValueType & lValue,
		const KeyType & rKey, const ValueType & rValue); // two keys
		~Node ();
};

template <class KeyType, class ValueType>
class TwoThreeTree : private std::vector<Node<KeyType, ValueType>> {
	public:
		void add(const KeyType & key, const ValueType & value);
		void remove(const KeyType & key);
		ValueType & get (const KeyType & key) const;
};



#endif /* TREE_H_ */
