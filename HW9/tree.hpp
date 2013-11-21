/*
 * tree.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: BryanChong
 */

#ifndef TREE_CPP_
#define TREE_CPP_

#include "tree.h"
#include "node.h"
#include <iostream>

template <class KeyType, class ValueType>
TwoThreeTree<KeyType, ValueType>::TwoThreeTree(const KeyType & key, const ValueType & value){
	_totalNodes = 0;
	_root = new Node<KeyType, ValueType>(key, value);
}

template <class KeyType, class ValueType>
ValueType & TwoThreeTree<KeyType, ValueType>::get(const KeyType & key) const{
	Node<KeyType, ValueType> tempnode = findsubtreeLeaf(this->_root, key);
	for (int i=0; i<3; i++){
		if (key == tempnode.child[i].leftKey){
			return tempnode.child[i].leftValue;
		}
		if (key == tempnode.child[i].rightKey){
			return tempnode.child[i].rightValue;
		}
		else{
			return NULL;
		}
	}
}


template <class KeyType, class ValueType>
Node<KeyType, ValueType> TwoThreeTree<KeyType, ValueType>::findsubtreeLeaf(Node<KeyType, ValueType> A, const KeyType & key){
	if(A.isLeaf == true){
		return A;
	}
	else{
		if(A.leftKey <= key){
			return findsubtreeLeaf(A.child[0], key);
		}
		else if (_totalNodes < 2 || A.rightKey <= key){
			return findsubtreeLeaf(A.child[1], key);
		}
		else{
			return findsubtreeLeaf(A.child[2], key);
		}
	}
}


template <class KeyType, class ValueType>
void TwoThreeTree<KeyType, ValueType>::add(const KeyType & key, const ValueType & value){
	Node <KeyType, ValueType> tnode(key, value);
	Node<KeyType, ValueType> tempnode = findsubtreeLeaf(this->_root, key);

	if (tempnode.leftKey == NULL){
		tempnode.leftKey = key;
		tempnode.leftValue = value;
	}
	else if (tempnode.leftKey != NULL && tempnode.rightKey == NULL){
		tempnode.rightKey = key;
		tempnode.rightValue = value;
	}

	tempnode.numberOfElements++;
	if (tempnode.numberOfElements >= 4){
		split(tempnode);
	}
	_totalNodes++;
}


template <class KeyType, class ValueType>
void TwoThreeTree<KeyType, ValueType>::split(Node<KeyType, ValueType> A){
	Node<KeyType, ValueType> newparent = A.parent;
	Node<KeyType, ValueType> sibling;
	KeyType x = A.rightKey;
	ValueType y = A.rightValue;

	sibling.isLeaf = A.isLeaf;
	if(sibling.isLeaf == true){
		sibling.leftKey = x;
		sibling.leftValue = y;
		sibling.numberOfElements = 2;
		A.numberOfElements = 2;
	}
	else{
		sibling.child[0] = A.child[3];
		sibling.child[1] = A.child[4];
		sibling.leftKey = A.rightKey;
		sibling.leftValue = A.rightValue;
		A.numberOfElements = 1;
		sibling.numberOfElements = 1;
	}
	if (newparent == NULL){
		Node<KeyType,ValueType> newroot;
		newroot.isLeaf = false;
		newroot.parent = NULL;
		newroot.child[0] = A;
		newroot.child[1] = sibling;

		if(A.isLeaf == true){
			newroot.leftKey = x;
			newroot.leftValue = y;
		}
		newroot.numberOfElements = 1;
		A.parent = newroot;
		sibling.parent = newroot;
	}
	else{
		for (int i =0; i < 4; i++){
			newparent.child[i+1] = newparent.child[i];
			newparent.rightKey = newparent.leftKey;
			newparent.rightValue = newparent.leftValue;
			newparent.child[i] = A;
			newparent.child[i+1] = sibling;
		}
		if (A.isLeaf == true){
			newparent.leftKey = A.leftKey;
			newparent.leftValue = A.leftValue;
			newparent.rightKey = A.rightKey;
			newparent.rightValue = A.rightValue;
		}
		newparent.numberOfElements++;
		sibling.parent = newparent;
		if(newparent.numberOfElements >= 3){
			splitNode(newparent);
		}
	}

}

template <class KeyType, class ValueType>
Node<KeyType, ValueType> TwoThreeTree<KeyType, ValueType>::mergeLeaf(Node<KeyType, ValueType> A, Node<KeyType, ValueType> B){
	Node<KeyType, ValueType> par = A.parent;

	if (A.numberOfElements == 1){
		A.midKey = B.leftKey;
		A.midValue = B.leftValue;
		A.rightKey = B.rightKey;
		A.rightValue = B.rightValue;
	}
	else{
		A.rightKey = B.leftKey;
		A.rightValue = B.leftValue;
	}
	delete(B);
	A.numberOfElements = 3;

	par.child[par.numberOfElements+1] = NULL;
	par.rightKey = NULL;
	par.rightValue = NULL;

	for (int i=0; i<3; i++){
		par.child[i] = par.child[i+1];
	}

	if (par.numberOfElements < 1){
		borrowInternal(par);
	}

}

template <class KeyType, class ValueType>
Node<KeyType, ValueType> TwoThreeTree<KeyType, ValueType>::mergeInternal(Node<KeyType, ValueType> A, Node<KeyType, ValueType> B){
	Node<KeyType, ValueType> par = A.parent;
	if(A.numberOfElements == 0){
		A.child[1] = B.child[0];
		A.child[2] = B.child[1];
	}

}


template <class KeyType, class ValueType>
void TwoThreeTree<KeyType, ValueType>::remove(const KeyType & key){
	Node<KeyType, ValueType> removable = findsubtreeLeaf(this->_root, key);
		if (removable.leftKey == key){
			removable.leftKey = NULL;
			removable.leftValue = NULL;
			if (removable.rightKey != NULL){
				removable.leftKey = removable.rightKey;
				removable.leftValue = removable.rightValue;
				removable.rightKey = NULL;
				removable.rightValue = NULL;
			}
		}
		if (removable.rightKey == key){
			removable.rightKey = NULL;
			removable.rightValue = NULL;
		}
		removable.numberOfElements--;
		if (removable.numberOfElements <= 1){
			borrowLeaf(removable);
		}
		_totalNodes--;
}

#endif /* TREE_CPP_ */
