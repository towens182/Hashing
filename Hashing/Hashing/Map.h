#pragma once
template <class valueType>
class Map
{
public:
	bool insert(string key, valueType value);	//adds a value to the map using the specified key
	valueType get(string key);			//returns the value associated with the specified key
	bool remove(string key);			//removes the value with the associated key
	int size();					//returns number of elements stored in the map
};


