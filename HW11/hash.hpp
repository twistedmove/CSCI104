/*
 * hash.hpp
 *
 *  Created on: Nov 21, 2013
 *      Author: BryanChong
 */

#ifndef HASH_HPP_
#define HASH_HPP_

#include <vector>
#include <string>
#include <iostream>
#include "hash.h"
#include <exception>

template <class KeyType, class ValueType>
Node<KeyType, ValueType>::Node(KeyType key, ValueType value){
	_key = key;
	_value = value;
}

template <class KeyType, class ValueType>
KeyType Node<KeyType, ValueType>::returnKey(){
	return _key;
}

template <class KeyType, class ValueType>
ValueType Node<KeyType, ValueType>::returnValue(){
	return _value;
}

template <class KeyType, class ValueType>
Hashtable<KeyType, ValueType>::Hashtable(int initialsize){
	_capacity = initialsize;	// total capacity of the vector
	hashList.reserve(initialsize);		// initialize the vector to be a prime multiple times the size of the input file
	_loadfactor = 0;
}


template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::checkLoad(){
	int newcapacity = nextPrime(_capacity*2);
	if (_loadfactor*2 >= _capacity){
		std::vector< std::vector<Node<KeyType, ValueType> > > newList;
		newList.reserve(newcapacity);
		int newloadfactor = 0;

		for (int i = 0; i<_capacity; i++){
			for (int j = 0; j <hashList[i].size(); j++){
				KeyType tempkey;
				ValueType tempvalue;
				tempkey = hashList[i][j].returnKey();
				tempvalue = hashList[i][j].returnValue();
				rehashAdd(tempkey, tempvalue, newList);
				newloadfactor++;
			}
		}
		_loadfactor = newloadfactor;
		hashList = newList;
		_capacity = newcapacity;
	}
}


template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::rehashAdd (const KeyType & key, const ValueType & value, std::vector< std::vector<Node<KeyType, ValueType> > > &newList){
	int index = createHash(key);
	Node<KeyType, ValueType> newNode(key, value);
	newList[index].push_back(newNode);
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::add (const KeyType & key, const ValueType & value){
	checkLoad();

	int index = createHash(key);
	Node<KeyType, ValueType> newNode(key, value);
	hashList[index].push_back(newNode);

	_loadfactor++;
}


template <class KeyType, class ValueType>
int Hashtable<KeyType, ValueType>::createHash(const KeyType & key){
	int index = 0;
	for (int i=0; i<key.length(); i++){
		index += (float)key[i];
	}
	index = index % _capacity;
	return index;
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::remove (const KeyType & key){
	int index = createHash(key);
	int counter = 0;
	int size = hashList[index].size();


	for (int i=0; i<hashList[index].size(); i++){
		counter++;
		if (hashList[index][i].returnKey() != key){
			std::cout << "Nothing found!" << std::endl;
		}
		if (size == 0){
			break;
		}
		else if (size == 1){
			hashList[index].pop_back();
			_loadfactor--;
			break;
		}
		else if (hashList[index][i].returnKey() == key){
			swap(index, i, size);
			hashList[index].pop_back();
			_loadfactor--;
			break;
		}
	}
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::swap(int index, int A, int B){
	Node<KeyType, ValueType> temp = hashList[index][A];
	hashList[index][A] = hashList[index][B];
	hashList[index][B] = temp;
}


template <class KeyType, class ValueType>
ValueType Hashtable<KeyType, ValueType>::get (const KeyType & key){
	int index = createHash(key);
	ValueType temp;
	for (int i =0; i <hashList[index].size(); i++){
		if (hashList[index][i].returnKey() == key){
			temp = hashList[index][i].returnValue();
			return temp;
		}
	}
	throw (std::logic_error("Key does not exist."));
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::print(){
	for (int i = 0; i<_capacity; i++){
		for (int j = 0; j <hashList[i].size(); j++){
			std::cout << hashList[i][j].returnKey() << " ";
			std::cout << hashList[i][j].returnValue() << std::endl;
		}
	}

}

template <class KeyType, class ValueType>
std::string Hashtable<KeyType, ValueType>::mostCommon(){
	KeyType mostkey;
	ValueType mostval;
	int biggestsize = 0;

	for (int i =0; i<_capacity; i++){
		for (int j = 0; j<hashList[i].size(); j++){
			if (biggestsize < hashList[i].size()){
				biggestsize = hashList[i].size();
				mostkey = hashList[i].back().returnKey();
				mostval = hashList[i].back().returnValue();
			}
		}
	}

	if (biggestsize != 1){
		return mostkey;
	}
	else{
		throw(std::logic_error("You only have one item! It's yours!"));
	}
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>:: destroy(){
	for (int i =0; i<_capacity; i++){
		hashList[i].clear();
	}
	hashList.clear();
	_loadfactor = 0;
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::findKey(const KeyType & key){
	int index = createHash(key);
	ValueType temp;
	for (int i =0; i <hashList[index].size(); i++){
		if (hashList[index][i].returnKey() == key){
			std::cout << "  >> " << hashList[index][i].returnValue() << std::endl;
		}
	}
}


template <class KeyType, class ValueType>
int Hashtable<KeyType, ValueType>:: nextPrime(int input){
	bool isPrime;
	int val;

	for(val = input+1;; val++){
		isPrime = true;
		for(int i = 2; i*i <= val; i++){
			if (val % i == 0){
				isPrime = false;
			}
		}
		if(isPrime == true){
			break;
		}
	}
	return val;
}
#endif /* HASH_HPP_ */
