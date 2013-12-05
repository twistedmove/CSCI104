/*
 * hash.h
 *
 *  Created on: Nov 21, 2013
 *      Author: BryanChong
 */

#ifndef HASH_H_
#define HASH_H_

#include <vector>
#include <string>

template <class KeyType, class ValueType>
struct Node {
	Node(KeyType, ValueType);
	KeyType _key;
	ValueType _value;

	KeyType returnKey();
	ValueType returnValue();
};

template <class KeyType, class ValueType>
class Hashtable {
	public:
		Hashtable (int initialSize);
		~Hashtable();

		void add (const KeyType & key, const ValueType & value);
		void remove (const KeyType & key);
		ValueType get (const KeyType & key);
		int createHash(const KeyType &);
		void swap(int, int, int);
		void print();
		void checkLoad();
		void rehashAdd(const KeyType & key, const ValueType & value, std::vector< std::vector<Node<KeyType, ValueType> > > &);
		std::string mostCommon();
		void destroy();
		void findKey(const KeyType & key);

		int nextPrime(int);

	private:
		std::vector< std::vector<Node<KeyType, ValueType> > > hashList;
		int _capacity;
		int _loadfactor;
};



#include "hash.hpp"

#endif /* HASH_H_ */
