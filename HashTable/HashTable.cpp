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
		Node<int, int> node1(111, 555);
		Node<int, int> node2(222, 666);

		// Int/String Nodes
		//Node <int, string> node1(123, "Hello");
		//Node <int, string> node2(456, "World");

	
		// String Nodes
		//Node <string, string> node1("H1", "Hello");
		//Node <string, string> node2("W1", "World");

		cout << "Node 1" << endl;
		cout << node1.getKey() << endl;
		cout << node1.getValue() << endl;

		cout << "Node 2" << endl;
		cout << node2.getKey() << endl;
		cout << node2.getValue() << endl;

		HashTable <int, int> table1;
		table1.insert(0, 000);
		table1.insert(1, 111);
		table1.insert(2, 222);
		table1.insert(3, 333);

		//table1.insert(111, "Hello");
		//table1.insert(222, "World");
}