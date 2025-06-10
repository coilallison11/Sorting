//****************************************************************************************************
//
//         File:                        SortedList.h
//
//         Student:                     Allison Coil
//
//         Assignment:                  Assignment  #10
//
//         Course Name:                 Data Structures   II
//
//         Course Number:               COSC 3100 - 01
//
//         Due:                         Nov 19, 2021
//
//
//         This class creates an array of an undetermined type and allows for the array to
//		   be randomized and sorted in a number of ways.
//
//****************************************************************************************************

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

//****************************************************************************************************

#include <cstdlib>
#include <ctime>
#include <iostream>

//****************************************************************************************************

template <typename TYPE>
class SortedList
{
	private:
	TYPE * list;
	int capacity;
	int numValues;
	void resize ();
	void swap (TYPE & first, TYPE & second);
	void quickSortA (int low, int high);
	void quickSortD (int low, int high);
	int partitionA (int low, int high);
	int partitionD (int low, int high);
	void heapifyA (int n, int root);
	void heapifyD (int n, int root);
	void heapSortA (int n);
	void heapSortD (int n);

	public:
	SortedList (int size);
	~SortedList ();
	void insert (const TYPE & item);
	void randomize ();
	void selectionSortA ();
	void selectionSortD ();
	void quickSortA ();
	void quickSortD ();
	void heapSortA ();
	void heapSortD ();
	void display ();
};

//****************************************************************************************************

template <typename TYPE>
SortedList <TYPE> :: SortedList (int size)
{
	capacity = size;
	list = new TYPE [capacity];
	numValues = 0;
}

//****************************************************************************************************

template <typename TYPE>
SortedList <TYPE> :: ~SortedList ()
{
	delete[] list;
	list = nullptr;
	capacity = 0;
	numValues = 0;
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: insert (const TYPE & item)
{
	if ( numValues >= capacity )
	{
		resize ();
	}

	list [numValues] = item;
	numValues ++;
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: resize ()
{
	capacity += 10;
	TYPE * newList = new TYPE [capacity];

	for ( int i = 0; i < numValues; i ++ )
	{
		newList [i] = list [i];
	}

	delete[] list;
	list = newList;
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: swap (TYPE & first, TYPE & second)
{
	TYPE temp = first;
	first = second;
	second = temp;
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: randomize ()
{
	const int MAX = numValues - 1;
	const int MIN = 0;
	unsigned seed = time (0);
	srand (seed);
	int index;

	for ( int i = 0; i < numValues; i ++ )
	{
		index = ( rand () % ( MAX - MIN + 1 ) ) + MIN;
		swap (list [i], list [index]);
	}
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: selectionSortA ()
{
	int smallest;

	for ( int i = 0; i < numValues; i ++ )
	{
		smallest = i;

		for ( int j = ( i + 1 ); j < numValues; j ++ )
		{
			if ( list [j] < list [smallest] )
			{
				smallest = j;
			}
		}

		if ( smallest != i )
		{
			swap (list [i], list [smallest]);
		}
	}
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: selectionSortD ()
{
	int largest;

	for ( int i = 0; i < numValues; i ++ )
	{
		largest = i;

		for ( int j = ( i + 1 ); j < numValues; j ++ )
		{
			if ( list [j] > list [largest] )
			{
				largest = j;
			}
		}

		if ( largest != i )
		{
			swap (list [i], list [largest]);
		}
	}
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: quickSortA ()
{
	quickSortA (0, numValues - 1);
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: quickSortA (int low, int high)
{
	if ( low < high )
	{
		int pivotLoc = partitionA (low, high);
		quickSortA (low, pivotLoc - 1);
		quickSortA (pivotLoc + 1, high);
	}
}

//****************************************************************************************************

template <typename TYPE>
int SortedList <TYPE> :: partitionA (int low, int high)
{
	TYPE pivot = list [( low + high ) / 2];
	swap (list [low], list [( low + high ) / 2]);
	int smallIndex = low;
	int index;

	for ( int i = ( low + 1 ); i <= high; i ++ )
	{
		index = i;

		if ( pivot > list [index] )
		{
			smallIndex ++;
			swap (list [index], list [smallIndex]);
		}
	}

	swap (list [low], list [smallIndex]);
	return smallIndex;
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: quickSortD ()
{
	quickSortD (0, numValues - 1);
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: quickSortD (int low, int high)
{
	if ( low < high )
	{
		int pivotLoc = partitionD (low, high);
		quickSortD (low, pivotLoc - 1);
		quickSortD (pivotLoc + 1, high);
	}
}

//****************************************************************************************************

template <typename TYPE>
int SortedList <TYPE> :: partitionD (int low, int high)
{
	TYPE pivot = list [( low + high ) / 2];
	swap (list [low], list [( low + high ) / 2]);
	int largeIndex = low;
	int index;

	for ( int i = ( low + 1 ); i <= high; i ++ )
	{
		index = i;

		if ( pivot < list [index] )
		{
			largeIndex ++;
			swap (list [index], list [largeIndex]);
		}
	}

	swap (list [low], list [largeIndex]);
	return largeIndex;
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: heapifyA (int n, int root)
{
	int largest = root;
	int l = ( 2 * root ) + 1;
	int r = ( 2 * root ) + 2;

	if ( ( l < n ) && ( list [l] > list [largest] ) )
	{
		largest = l;
	}
	if ( ( r < n ) && ( list [r] > list [largest] ) )
	{
		largest = r;
	}

	if ( largest != root )
	{
		swap (list [root], list [largest]);
		heapifyA (n, largest);
	}
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: heapifyD (int n, int root)
{
	int smallest = root;
	int l = ( 2 * root ) + 1;
	int r = ( 2 * root ) + 2;

	if ( ( l < n ) && ( list [l] < list [smallest] ) )
	{
		smallest = l;
	}
	if ( ( r < n ) && ( list [r] < list [smallest] ) )
	{
		smallest = r;
	}

	if ( smallest != root )
	{
		swap (list [root], list [smallest]);
		heapifyD (n, smallest);
	}
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: heapSortA ()
{
	heapSortA (numValues);
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: heapSortA (int n)
{
	for ( int i = ( n / 2 ) - 1; i >= 0; i -- )
	{
		heapifyA (n, i);
	}

	for ( int i = n - 1; i >= 0; i -- )
	{
		swap (list [0], list [i]);
		heapifyA (i, 0);
	}
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: heapSortD ()
{
	heapSortD (numValues);
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: heapSortD (int n)
{
	for ( int i = ( n / 2 ) - 1; i >= 0; i -- )
	{
		heapifyD (n, i);
	}

	for ( int i = n - 1; i >= 0; i -- )
	{
		swap (list [0], list [i]);
		heapifyD (i, 0);
	}
}

//****************************************************************************************************

template <typename TYPE>
void SortedList <TYPE> :: display ()
{
	for ( int i = 0; i < numValues; i ++ )
	{
		std::cout << list [i];
	}

	std::cout << std::endl;
}

//****************************************************************************************************

#endif