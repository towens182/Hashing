#pragma once
#include <functional>
#include <vector>
#include <string>
template <class valueType>
class Map
{

public:

	Map<valueType>();
	~Map<valueType>();

	bool insert(std::string key, valueType value);	//adds a value to the map using the specified key
	valueType get(std::string key);			//returns the value associated with the specified key
	bool remove(std::string key);			//removes the value with the associated key
	int size();						//returns number of elements stored in the map
	bool keyFound(std::string key);

private:
	std::vector<std::size_t> keyV;
	std::vector<valueType> objV;
};

template<class valueType>
inline Map<valueType>::Map()
{
}

template <class valueType>
inline Map<valueType>::~Map()
{
	//must delete elements from vectors
}


template<class valueType>
inline bool Map<valueType>::insert(std::string key, valueType value)
{
	std::hash<std::string> hash_fn;

	if (keyFound(key) == false)
	{

		keyV.push_back(hash_fn(key));
		objV.push_back(value);

		return true;
	}
	else
	{
		std::cout << "Entry already exists with " << key << std::endl;
		return false;
	}
}

template<class valueType>
inline valueType Map<valueType>::get(std::string key)
{
	std::hash<std::string> hash_fn;
	int counter = 0;
	for (std::vector<std::size_t>::iterator it = keyV.begin(); it != keyV.end(); ++it)
	{
		if (*it == hash_fn(key))
		{
			return objV[counter];
		}
		counter++;
	}
	
}

template<class valueType>
inline bool Map<valueType>::remove(std::string key)
{
	std::hash<std::string> hash_fn;
	int counter = 0;
	for (std::vector<std::size_t>::iterator it = keyV.begin(); it != keyV.end(); ++it)
	{

		if (*it == hash_fn(key))
		{
			keyV.erase(keyV.begin()+counter);
			objV.erase(objV.begin()+counter);

			return true;
		}

		counter++;
	}

	return false;
}

template <class valueType>
inline int Map<valueType>::size()
{
	return keyV.size();
}

template<class valueType>
inline bool Map<valueType>::keyFound(std::string key)
{
	std::hash<std::string> hash_fn;

	for (std::vector<std::size_t>::iterator it = keyV.begin(); it != keyV.end(); ++it)
	{
		if (*it == hash_fn(key))
		{
			return true;
		}
	}

	return false;
}
