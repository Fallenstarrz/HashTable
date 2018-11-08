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

template<typename K, typename V>
class HashTable
{
private:
	int tableSize = 10;
	Node<K, V>** table;
public:
// Methods
// Constructors
	HashTable()
	{
		table = new Node<K, V>* [tableSize];
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
		int hash = makeHash(keyToInsert);

		if (table[hash] == nullptr)
		{
			table[hash] = new Node<K, V>(keyToInsert, valueToInsert);
		}
		else
		{
			Node<K,V>* temp = table[hash];
			while (temp->getNextNode() != nullptr)
			{
				temp = temp->getNextNode();
			}
			if (temp->getKey() == keyToInsert)
			{
				temp->setValue(valueToInsert);
			}
			else
			{
				Node<K, V>* nodeToInsert = new Node<K, V>(keyToInsert, valueToInsert);
				temp->setNextNode(nodeToInsert);
			}
		}

	}
// Retrieve function to get info from the HashTable
	Node<K,V>* retrieve(K keyToFind)
	{
		// DO SOME STUFF
	}

	// Formula to hash
	// tableSize is item to mod by
	int makeHash(K keyToHash){ return keyToHash % tableSize; }

	Node<K, V>* getNodeFromTable(int num)
	{
		return table[num];
	}
};