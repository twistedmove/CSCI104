/*
 * node.hpp
 *
 *  Created on: Nov 18, 2013
 *      Author: BryanChong
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <string>

template <class KeyType, class ValueType>
Node<KeyType, ValueType>::Node (const KeyType & key, const ValueType & value): leftKey(key), leftValue(value){
	numberOfElements = 0;
	parent = NULL;
	_isLeaf = true;
	//child = new Node<KeyType, ValueType>[4];
}

template <class KeyType, class ValueType>
Node<KeyType, ValueType>::Node (const KeyType & lKey, const ValueType & lValue, const KeyType & rKey, const ValueType & rValue): leftKey(lKey), rightKey(rKey), leftValue(lValue), rightValue(rValue){
	numberOfElements = 0;
	parent = NULL;
	_isLeaf = true;
	//child = new Node<KeyType, ValueType>[4];
}

template <class KeyType, class ValueType>
Node<KeyType, ValueType>::~Node (){}

template <class KeyType, class ValueType>
void Node<KeyType, ValueType>::setnumberOfKeys(int val){
	numberOfElements = val;
}

template <class KeyType, class ValueType>
std::string Node<KeyType, ValueType>::getType(){
	std::string type = "empty";
	if (leftKey != 0 && rightKey != 0){
		type = "threeNode";
	}
	else if ((leftKey != 0 && rightKey == 0) || (rightKey != 0 && leftKey == 0)){
		type = "twoNode";
	}
	return type;
}


#endif /* NODE_HPP_ */
