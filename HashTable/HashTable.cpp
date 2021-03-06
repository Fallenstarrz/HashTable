// HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program is a hash table that uses chaining to handle collisions

#include "pch.h"
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

// Run every case you can think of without the user needing to input data
void automatedTest()
{
	// Int Nodes
	Node<int, int> nodeIntInt1(111, 555);
	Node<int, int> nodeIntInt2(222, 666);

	cout << "Node Int Int 1" << endl;
	cout << nodeIntInt1.getKey() << endl;
	cout << nodeIntInt1.getValue() << endl;

	cout << "Node Int Int 2" << endl;
	cout << nodeIntInt2.getKey() << endl;
	cout << nodeIntInt2.getValue() << endl;
	cout << endl;

	// Int/String Nodes
	Node <int, string> nodeIntStr1(123, "Hello");
	Node <int, string> nodeIntStr2(456, "World");

	cout << "Node Int Str 1" << endl;
	cout << nodeIntStr1.getKey() << endl;
	cout << nodeIntStr1.getValue() << endl;

	cout << "Node Int Str 2" << endl;
	cout << nodeIntStr2.getKey() << endl;
	cout << nodeIntStr2.getValue() << endl;
	cout << endl;

	// String Nodes
	Node <string, string> nodeStrStr1("H1", "Hello");
	Node <string, string> nodeStrStr2("W1", "World");

	cout << "Node Str Str 1" << endl;
	cout << nodeStrStr1.getKey() << endl;
	cout << nodeStrStr1.getValue() << endl;

	cout << "Node Str Str" << endl;
	cout << nodeStrStr2.getKey() << endl;
	cout << nodeStrStr2.getValue() << endl;
	cout << endl;

	// Int int table Tests
	HashTable <int, int> table1;
	cout << "Int-Int Table Tests" << endl;

	cout << "Insert Tests" << endl;
	table1.insert(0, 000);
	table1.insert(1, 111);
	table1.insert(2, 222);
	table1.insert(3, 333);
	table1.insert(10, 1010);
	table1.insert(11, 1111);
	table1.insert(12, 1212);
	table1.insert(13, 1313);
	table1.insert(23, 2323);

	cout << "Retrieve Tests" << endl;
	cout << table1.retrieve(0)->getValue() << endl;
	cout << table1.retrieve(1)->getValue() << endl;
	cout << table1.retrieve(2)->getValue() << endl;
	cout << table1.retrieve(3)->getValue() << endl;
	cout << table1.retrieve(10)->getValue() << endl;
	cout << table1.retrieve(11)->getValue() << endl;
	cout << table1.retrieve(12)->getValue() << endl;
	cout << table1.retrieve(13)->getValue() << endl;
	cout << table1.retrieve(23)->getValue() << endl;

	// int string table tests
	HashTable <int, string> table2;
	cout << "Int-String Table Tests" << endl;

	cout << "Insert Tests" << endl;
	table2.insert(0, "000");
	table2.insert(1, "111");
	table2.insert(2, "222");
	table2.insert(3, "333");
	table2.insert(10, "1010");
	table2.insert(11, "1111");
	table2.insert(12, "1212");
	table2.insert(13, "1313");
	table2.insert(23, "2323");

	cout << "Retrieve Tests" << endl;
	cout << table2.retrieve(0)->getValue() << endl;
	cout << table2.retrieve(1)->getValue() << endl;
	cout << table2.retrieve(2)->getValue() << endl;
	cout << table2.retrieve(3)->getValue() << endl;
	cout << table2.retrieve(10)->getValue() << endl;
	cout << table2.retrieve(11)->getValue() << endl;
	cout << table2.retrieve(12)->getValue() << endl;
	cout << table2.retrieve(13)->getValue() << endl;
	cout << table2.retrieve(23)->getValue() << endl;

	// string string table tests
	HashTable <string, string> table3;
	cout << "String-String Table Tests" << endl;

	cout << "Insert Tests" << endl;
	table3.insert("Item-0", "000");
	table3.insert("Item-1", "111");
	table3.insert("Item-2", "222");
	table3.insert("Item-3", "333");
	table3.insert("Item-10", "1010");
	table3.insert("Item-11", "1111");
	table3.insert("Item-12", "1212");
	table3.insert("Item-13", "1313");
	table3.insert("Item-23", "2323");

	cout << "Retrieve Tests" << endl;
	cout << table3.retrieve("Item-0")->getValue() << endl;
	cout << table3.retrieve("Item-1")->getValue() << endl;
	cout << table3.retrieve("Item-2")->getValue() << endl;
	cout << table3.retrieve("Item-3")->getValue() << endl;
	cout << table3.retrieve("Item-10")->getValue() << endl;
	cout << table3.retrieve("Item-11")->getValue() << endl;
	cout << table3.retrieve("Item-12")->getValue() << endl;
	cout << table3.retrieve("Item-13")->getValue() << endl;
	cout << table3.retrieve("Item-23")->getValue() << endl;

	// Invalid testing
	string testing = "Does Not Exist";
	cout << "Invalid option tests" << endl;
	if (table3.retrieve(testing) != nullptr)
	{
		cout << table3.retrieve(testing) << endl;
	}
	else
	{
		cout << testing << " Is not in the table" << endl;
	}
}

// Insert node to tree
template<typename K, typename V>
void insertNode(K keyToInsert, V valueToInsert, HashTable<K,V> table)
{
	table.insert(keyToInsert, valueToInsert);
}

// Retrieve node from tree
template<typename K, typename V>
void retrieveNode(K keyToRetrieve, HashTable<K, V> table)
{
	if (table.retrieve(keyToRetrieve))
	{
		cout << "Key is: " << table.retrieve(keyToRetrieve)->getKey() << endl;
		cout << "Value is: " << table.retrieve(keyToRetrieve)->getValue() << endl;
	}
	else
	{
		cout << "Value not found in table" << endl;
	}
}

// Delete node from tree
template<typename K, typename V>
void deleteNode(K keyToRetrieve, HashTable<K,V> table)
{
	// Not implemented right now. Will address at a later time, if I have time before submission
	cout << "Not yet implemented" << endl;
}

// Simply display the menu
void displayMenu()
{
	cout << "Menu Options:" << endl;
	cout << "1. Insert Node to Table" << endl;
	cout << "2. Lookup Node in Table" << endl;
	cout << "3. Delete Node in Table" << endl;
	cout << "4. Complete Automated Suite" << endl;
	cout << "99. Exit Program" << endl;
}

// Display a welcome screen with a brief introduction to the program
void displayStart()
{
	cout << "Welcome to my Hash Table tryout program" << endl;
	cout << "This is a templated hash table" << endl;
	cout << "For the purposes of this test the default table is string key and string value" << endl;
	system("pause");
}

int main()
{
	// variables
	int choice;
	string chosenKey;
	string chosenValue;
	HashTable <string, string> stringTable;

	displayStart();

	// main program loop
	do
	{
		displayMenu();
		cout << "Please select a menu option" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				cout << "Choose a key to insert" << endl;
				cin >> chosenKey;
				cout << endl << "Choose a value to insert" << endl;
				cin >> chosenValue;
				cout << endl;
				insertNode(chosenKey, chosenValue, stringTable);
				break;
			}
			case 2:
			{
				cout << "What node would you like to look up?" << endl;
				cin >> chosenKey;
				cout << endl;
				retrieveNode(chosenKey, stringTable);
				break;
			}
			case 3:
			{
				cout << "What node would you like to delete?" << endl;
				cin >> chosenKey;
				cout << endl;
				deleteNode(chosenKey, stringTable);
				break;
			}
			case 4:
			{
				automatedTest();
				break;
			}
			case 99:
			{
				cout << "Exiting Program" << endl;
				break;
			}
			default:
			{
				cout << "Invalid option selected" << endl;
				cout << "Please select a valid option from the menu" << endl;
				break;
			}
		}
		system("pause");
		system("cls");
	} while (choice != 99);
}