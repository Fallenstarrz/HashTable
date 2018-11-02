#pragma once

// Hash table node class
// These store the values, keys and a pointer to the next Node at index.
template<typename genericType>
class Node
{
private:
	genericType key;
	genericType value;
	Node<genericType>* nextNode;
public:
// Methods
// Constructors
	Node()
	{
		key = NULL;
		value = NULL;
		nextNode = nullptr;
	}
	Node(genericType newKey)
	{
		key = newKey;
		value = NULL;
		nextNode = nullptr;
	}
	Node(genericType newKey, genericType newValue)
	{
		key = newKey;
		value = newValue;
		nextNode = nullptr;
	}
	Node(genericType newKey, genericType newValue, Node<genericType>* newNextNode)
	{
		key = newKey;
		value = newValue;
		nextNode = newNextNode;
	}
// Deconstructors
	~Node()
	{
		key = NULL;
		value = NULL;
		nextNode = nullptr;
	}

// Getters
	genericType getKey()
	{
		return key;
	}
	genericType getValue()
	{
		return value;
	}
	Node<genericType>* getNextNode()
	{
		return nextNode;
	}
// Setters
	void setKey(genericType newKey)
	{
		key = newKey;
	}
	void setValue(genericType newValue)
	{
		value = newValue;
	}
	void setNextNode(genericType newNextNode)
	{
		nextNode = newNextNode;
	}
};

template<typename genericType>
class HashTable
{
private:
	const int tableSize = 10;
	int table[tableSize];
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
	Node<genericType>* insert(genericType keyToInsert, genericType valueToInsert)
	{

	}
// Retrieve function to get info from the HashTable
	Node<genericType>* retrieve(genericType keyToFind)
	{

	}
};