#pragma once

#include <string>

// Hash table node class
// These store the values, keys and a pointer to the next Node at index.
template<typename K, typename V>
class Node
{
private:
	K key;
	V value;
	Node<K,V>* nextNode;
public:
// Methods
// Constructors
	Node(K newKey, V newValue)
	{
		key = newKey;
		value = newValue;
		nextNode = nullptr;
	}
	Node(K, V, Node<K,V>* newNextNode)
	{
		key = newKey;
		value = newValue;
		nextNode = newNextNode;
	}
// Deconstructors
	~Node()
	{
		nextNode = nullptr;
	}

// Getters
	K getKey() { return key; }
	V getValue() { return value; }
	Node<K, V>* getNextNode() { return nextNode; }

// Setters
	void setKey(K newKey) { key = newKey; }
	void setValue(V newValue) { value = newValue; }
	void setNextNode(Node<K, V>* newNextNode) { nextNode = newNextNode; }
};

template<typename K, typename V>
class HashTable
{
private:
	const int tableSize = 10;
	Node<K,V> table = Node<K,V>[tableSize];
public:
// Methods
// Constructors
	HashTable()
	{

	}
// Deconstructors
	~HashTable()
	{

	}
// Insert function to add a node to the HashTable
	Node<K,V>* insert(K keyToInsert, V valueToInsert)
	{

	}
// Retrieve function to get info from the HashTable
	Node<K,V>* retrieve(K keyToFind)
	{

	}
};