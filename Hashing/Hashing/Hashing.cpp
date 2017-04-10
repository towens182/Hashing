// Hashing.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <functional>

int main()
{
	using namespace std;
	cout << "Creating three maps of type int, double, and string." << endl;

	Map<int> * intMap = new Map<int>();
	Map<double> * doubleMap = new Map<double>();
	Map<string> * stringMap = new Map<string>();

	cout << "Size of maps." << endl;
	cout << "Size of intMap: " << intMap->size() << endl;
	cout << "Size of floatMap: " << doubleMap->size() << endl;
	cout << "Size of stringMap: " << stringMap->size() << endl << endl;

	cout << "Adding 100 elements to each map." << endl;


	//Add elements to maps
	for (int i = 1; i < 101; i++)
	{
		string mapInput = "Key";

		mapInput = mapInput + to_string(i);

		intMap->insert(mapInput, i);
		doubleMap->insert(mapInput, i + .5);
		stringMap->insert(mapInput, to_string(i));
	}

	cout << "Size of intMap: " << intMap->size() << endl;
	cout << "Size of doubleMap: " << doubleMap->size() << endl;
	cout << "Size of stringMap: " << stringMap->size() << endl << endl;

	cout << "Now removing various items" << endl;


	if (intMap->remove("Key105") == true)
	{
		cout << "Removed Key105 from intMap" << endl;
	}
	else
	{
		cout << "Did not remove Key105 in intMap" << endl;
	}

	for (int i = 32; i < 36; i++)
	{
		if (doubleMap->remove("Key" + to_string(i)) == true)
		{
			cout << "Removed Key" << i << " from doubleMap" << endl;
		}
		else
		{
			cout << "Did not remove Key" << i << " from doubleMap" << endl;
		}
	}

	if (stringMap->remove("Key101") == true)
	{
		cout << "Removed Key101 from stringMap" << endl;
	}
	else
	{
		cout << "Did not remove Key101 in stringMap" << endl;
	}
	if (stringMap->remove("Key24") == true)
	{
		cout << "Removed Key24 from stringMap" << endl;
	}
	else
	{
		cout << "Did not remove Key24 in stringMap" << endl;
	}
	cout << endl;
	cout << "Size of intMap: " << intMap->size() << endl;
	cout << "Size of doubleMap: " << doubleMap->size() << endl;
	cout << "Size of stringMap: " << stringMap->size() << endl << endl;

	try
	{
		cout << "Now attempting to add vaious elements." << endl;
		if (intMap->insert("Key101", 101) == true)
		{
			cout << "Added Key101 to intMap" << endl;
		}
		if (intMap->insert("Key3", 3) == true)
		{
			cout << "Added Key3 to intMap" << endl;
		}
		if (intMap->insert("Key", 2) == true)
		{
			cout << "Added Key2 to intMap" << endl;
		}
		if (doubleMap->insert("Key101", 101.5) == true)
		{
			cout << "Added Key101 to doubleMap" << endl;
		}
		cout << endl;
		cout << "Size of intMap: " << intMap->size() << endl;
		cout << "Size of doubleMap: " << doubleMap->size() << endl;
		cout << "Size of stringMap: " << stringMap->size() << endl << endl;

		cout << "Getting values in intMap" << endl;
		for (int i = 5; i < 8; i++)
		{
			cout << "Key" << i << "\tValue: " << intMap->get("Key" + to_string(i)) << endl;
		}

		cout << endl;
		cout << "Getting values in doubleMap" << endl;
		for (int i = 56; i < 59; i++)
		{
			cout << "Key" << i << "\tValue: " << doubleMap->get("Key" + to_string(i)) << endl;
		}

		cout << endl;
		cout << "Getting values in stringMap" << endl;
		for (int i = 23; i < 25; i++)
		{
			cout << "Key" << i << "\tValue: " << stringMap->get("Key" + to_string(i)) << endl;
		}
		
}
	catch (string error)
	{
		cout << error << endl;
	}
	try {
		cout << "Key25" << "\tValue: " << stringMap->get("Key25") << endl;
		cout << "Key120" << "\tValue: " << stringMap->get("Key120") << endl;

	}
	catch (string error)
	{

		cout << error << endl;

	}

	//Cleanup
	delete intMap;
	delete doubleMap;
	delete stringMap;

    return 0;
}

