/*
 * tree.h
 *
 *  Created on: Nov 15, 2013
 *      Author: BryanChong
 */

#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include "node.h"

template <class KeyType, class ValueType>
class TwoThreeTree : private std::vector<Node<KeyType, ValueType> > {
	public:

		TwoThreeTree(const KeyType & key, const ValueType & value);
		KeyType search(const KeyType & key);
		Node<KeyType, ValueType> findsubtreeLeaf(Node<KeyType, ValueType>, const KeyType & key);

		void add(const KeyType & key, const ValueType & value);
		void split(Node<KeyType, ValueType>);
		void remove(const KeyType & key);
		ValueType & get (const KeyType & key) const;

		Node<KeyType, ValueType> mergeLeaf(Node<KeyType, ValueType>, Node<KeyType, ValueType>);
		Node<KeyType, ValueType> mergeInternal(Node<KeyType, ValueType>, Node<KeyType, ValueType>);
		void borrowLeaf(Node<KeyType, ValueType>);
		void borrowInternal(Node<KeyType, ValueType>);


	private:
		int _totalNodes;
		Node<KeyType, ValueType> *_root;
};


#include "tree.hpp"


#endif /* TREE_H_ */
