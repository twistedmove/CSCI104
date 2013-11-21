/*
 * node.h
 *
 *  Created on: Nov 18, 2013
 *      Author: BryanChong
 */

#ifndef NODE_H_
#define NODE_H_

#include "tree.h"
#include <string>

template <class KeyType, class ValueType>
class Node {
	public:
		Node (const KeyType & key, const ValueType & value); // one key only
		Node (const KeyType & lKey, const ValueType & lValue, const KeyType & rKey, const ValueType & rValue); // two keys
		~Node (); // nothing dynamically

		bool returnisLeaf();

		void setnumberOfKeys(int);
		std::string getType();

		bool _isLeaf;
		int numberOfElements;	// elements in this node
		KeyType leftKey, rightKey;
		ValueType leftValue, rightValue;
		KeyType midKey;
		ValueType midValue;

		Node<KeyType, ValueType> *parent;	// i know you want the index, but i'm going to make it a pointer for simplicity sake
		Node<KeyType, ValueType> child[4];

};

#include "node.hpp"

#endif /* NODE_H_ */
