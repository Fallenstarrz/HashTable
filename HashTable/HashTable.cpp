// HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program is a hash table that uses chaining to handle collisions

#include "pch.h"
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

int main()
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

		// Int Tests
		HashTable <int, int> table1;
		cout << "Table Tests" << endl;

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

		system("pause");
}