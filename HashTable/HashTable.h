#pragma once

#include <functional>

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
	Node(K newKey, V newValue, Node<K,V>* newNextNode)
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

// Hash table class
// Stores value for tableSize and mods they keys of the nodes it contains to index them into the array
template<typename K, typename V>
class HashTable
{
private:
	// Table size to mod by to store data
	int tableSize = 10;
	// Pointer to an array that holds pointers to nodes
	Node<K, V>** table;
public:
// Methods
// Constructors
	HashTable()
	{
		// make a new table on start
		table = new Node<K, V>* [tableSize];
		// set the tables indexes to nullptr
		for (int i = 0; i < tableSize; i++)
		{
			table[i] = nullptr;
		}
	}
// Deconstructors
	~HashTable()
	{

	}
// Insert function to add a node to the HashTable
	void insert(K keyToInsert, V valueToInsert)
	{
		// Hash the key and use the return of the hashKey function to pick spot in the table
		int hashKey = makeHash(keyToInsert);
		// if index of the hash is nullpt
		if (table[hashKey] == nullptr)
		{
			// create a node and put its location in the table at the index
			table[hashKey] = new Node<K, V>(keyToInsert, valueToInsert);
		}
		// if index of the hash is not nullptr
		else
		{
			// get the node at that index
			Node<K,V>* temp = table[hashKey];
			// check the next of the temp node until it is null
			while (temp->getNextNode() != nullptr)
			{
				// if the temp key is the same key we are trying to insert change the value to the value we are trying to insert instead and return from the function
				if (temp->getKey() == keyToInsert)
				{
					temp->setValue(valueToInsert);
					return;
				}
				// otherwise make temp the node stored in the nodes next node
				temp = temp->getNextNode();
			}
			// if the next node is nullpt then create a node
			Node<K, V>* nodeToInsert = new Node<K, V>(keyToInsert, valueToInsert);
			// then set the temps next node to the newly created node
			temp->setNextNode(nodeToInsert);
		}
	}
// Retrieve function to get info from the HashTable
	Node<K,V>* retrieve(K keyToFind)
	{
		// Hash the key and use the return of the hashKey function to find the index our item is stored at
		int hashKey = makeHash(keyToFind);

		// if the index stored at this point is nullptr
		if (table[hashKey] == nullptr)
		{
			// leave function and return nullptr
			return nullptr;
		}
		else
		{
			// get the node at that index
			Node<K, V>* temp = table[hashKey];
			// while the node isn't nullptr and the key is not the key to find
			while (temp != nullptr && temp->getKey() != keyToFind)
			{
				// make temp the next node of the temp node
				temp = temp->getNextNode();
			}
			// if the node is nullptr return nullptr
			if (temp == nullptr)
			{
				return nullptr;
			}
			// otherwise return a ptr to the node that we are looking for
			else
			{
				return temp;
			}
		}
	}

	// Formula to hash
	// Used standard library to get a hash number and mod that number by tableSize
	int makeHash(K keyToHash)
	{ 
		size_t hashBase = hash<K>() (keyToHash);
		int hashedKey = hashBase % tableSize;

		return hashedKey;
	}

};