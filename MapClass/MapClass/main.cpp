#include <iostream>
#include <cstdlib>

#include "Map.h"
#include "Dictionary.h"

int main()
{

	// Create Map object
	Map<int, int> * myMap = new Map<int, int>();

	// Adding keys and values
	myMap->Add(12, 13);
	myMap->Add(15, 11);
	myMap->Add(1, 13);
	myMap->Add(55, 24);
	myMap->Add(35, 24);

	// Retrieve number of elements (Count)
	std::cout << "Number of elements: " << std::endl;
	std::cout << myMap->Count() << std::endl;

	// Removing a key
	myMap->Remove(35);

	// Retrieve number of elements after deletion
	std::cout << "Number of elements after deletion: " << std::endl;
	std::cout << myMap->Count() << std::endl;

	// Clear Map
	myMap->Clear();
	std::cout << "Number of elements after clearing: " << std::endl;
	std::cout << myMap->Count() << std::endl;

	myMap->Add(12, 13);
	myMap->Add(15, 11);
	myMap->Add(1, 13);
	myMap->Add(55, 24);

	// HasKey and HasValue
	std::cout << "Looking for Key 12: " << std::endl;
	if (myMap->HasKey(12)) // 12 exits
	{
		std::cout << "Key found!" << std::endl;
	}
	else
	{
		std::cout << "Key not found!" << std::endl;
	}

	std::cout << "Looking for Value 99: " << std::endl;
	if (myMap->HasValue(99)) // 99 does not exits
	{
		std::cout << "Value found!" << std::endl;
	}
	else
	{
		std::cout << "Value not found!" << std::endl;
	}

	// To Array
	int * arr = new int[myMap->Count()];
	myMap->ToArray(&arr);
	std::cout << "Printing array from Map: " << std::endl;
	for (int i = 0; i < myMap->Count(); i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;

	// Subscript operator
	std::cout << "Using subscript operator: " << std::endl;
	try
	{
		(*myMap)[15] = 42;
		std::cout << (*myMap)[15] << std::endl;
	}
	catch (const char * msg)
	{
		std::cout << msg << std::endl;
	}

	// << operator
	std::cout << "Using ostream operator: " << std::endl;
	std::cout << *myMap << std::endl;

	// Assingment operator
	Map<int, int> * yourMap = new Map<int, int>();
	yourMap = myMap;
	std::cout << "Using assignment operator: " << std::endl;
	std::cout << "yourMap: " << *yourMap << std::endl;


	getchar();
	return 0;
}