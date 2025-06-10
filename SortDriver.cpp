//****************************************************************************************************
//
//         File:                        SortDriver.cpp
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
//         This program acts as a driver for the SortedList class.
//		   
//
//****************************************************************************************************

#include "Stock.h"
#include "SortedList.h"
#include <iostream>
#include <fstream>
using namespace std;

//****************************************************************************************************

int main ()
{
	SortedList <Stock> list (10);
	fstream file ("Stock.txt");
	string name;
	string symbol;
	double price;
	Stock tempStock;

	for ( int i = 0; i < 11; i ++ )
	{
		if ( i > 0 )
		{
			file.ignore ();
		}

		getline (file, name);
		tempStock.setName (name);
		file >> symbol;
		tempStock.setSymbol (symbol);
		file >> price;
		tempStock.setPrice (price);
		list.insert (tempStock);
	}

	file.close ();

	cout << "Original List:" << endl;
	list.display ();
	cout << "Randomized List:" << endl;
	list.randomize ();
	list.display ();

	cout << "Selection Sort Ascending:" << endl;
	list.selectionSortA ();
	list.display ();

	list.randomize ();
	cout << "Selection Sort Descending:" << endl;
	list.selectionSortD ();
	list.display ();

	list.randomize ();
	cout << "Quick Sort Ascending:" << endl;
	list.quickSortA ();
	list.display ();

	list.randomize ();
	cout << "Quick Sort Descending:" << endl;
	list.quickSortD ();
	list.display ();

	list.randomize ();
	cout << "Heap Sort Ascending:" << endl;
	list.heapSortA ();
	list.display ();

	list.randomize ();
	cout << "Heap Sort Descending:" << endl;
	list.heapSortD ();
	list.display ();

	return 0;
}

//****************************************************************************************************

/*
Original List:
Motorola Inc.            MOT       $17.49
Microsoft Corp.          MSFT      $28.11
Tesla                    TSLA      $564.33
Intel                    INTC      $60.78
Sony                     SNE       $105.81
Advanced Micro Devices   AMD       $84.51
NVIDIA                   NVDA      $548.58
Apple                    AAPL      $121.73
Ford Motor               F         $11.7
General Electric         GE        $12.54
Emerson Electric Co.     EMR       $94.57

Randomized List:
Motorola Inc.            MOT       $17.49
Sony                     SNE       $105.81
Intel                    INTC      $60.78
Advanced Micro Devices   AMD       $84.51
Tesla                    TSLA      $564.33
Apple                    AAPL      $121.73
NVIDIA                   NVDA      $548.58
Ford Motor               F         $11.7
General Electric         GE        $12.54
Emerson Electric Co.     EMR       $94.57
Microsoft Corp.          MSFT      $28.11

Selection Sort Ascending:
Apple                    AAPL      $121.73
Advanced Micro Devices   AMD       $84.51
Emerson Electric Co.     EMR       $94.57
Ford Motor               F         $11.7
General Electric         GE        $12.54
Intel                    INTC      $60.78
Motorola Inc.            MOT       $17.49
Microsoft Corp.          MSFT      $28.11
NVIDIA                   NVDA      $548.58
Sony                     SNE       $105.81
Tesla                    TSLA      $564.33

Selection Sort Descending:
Tesla                    TSLA      $564.33
Sony                     SNE       $105.81
NVIDIA                   NVDA      $548.58
Microsoft Corp.          MSFT      $28.11
Motorola Inc.            MOT       $17.49
Intel                    INTC      $60.78
General Electric         GE        $12.54
Ford Motor               F         $11.7
Emerson Electric Co.     EMR       $94.57
Advanced Micro Devices   AMD       $84.51
Apple                    AAPL      $121.73

Quick Sort Ascending:
Apple                    AAPL      $121.73
Advanced Micro Devices   AMD       $84.51
Emerson Electric Co.     EMR       $94.57
Ford Motor               F         $11.7
General Electric         GE        $12.54
Intel                    INTC      $60.78
Motorola Inc.            MOT       $17.49
Microsoft Corp.          MSFT      $28.11
NVIDIA                   NVDA      $548.58
Sony                     SNE       $105.81
Tesla                    TSLA      $564.33

Quick Sort Descending:
Tesla                    TSLA      $564.33
Sony                     SNE       $105.81
NVIDIA                   NVDA      $548.58
Microsoft Corp.          MSFT      $28.11
Motorola Inc.            MOT       $17.49
Intel                    INTC      $60.78
General Electric         GE        $12.54
Ford Motor               F         $11.7
Emerson Electric Co.     EMR       $94.57
Advanced Micro Devices   AMD       $84.51
Apple                    AAPL      $121.73

Heap Sort Ascending:
Apple                    AAPL      $121.73
Advanced Micro Devices   AMD       $84.51
Emerson Electric Co.     EMR       $94.57
Ford Motor               F         $11.7
General Electric         GE        $12.54
Intel                    INTC      $60.78
Motorola Inc.            MOT       $17.49
Microsoft Corp.          MSFT      $28.11
NVIDIA                   NVDA      $548.58
Sony                     SNE       $105.81
Tesla                    TSLA      $564.33

Heap Sort Descending:
Tesla                    TSLA      $564.33
Sony                     SNE       $105.81
NVIDIA                   NVDA      $548.58
Microsoft Corp.          MSFT      $28.11
Motorola Inc.            MOT       $17.49
Intel                    INTC      $60.78
General Electric         GE        $12.54
Ford Motor               F         $11.7
Emerson Electric Co.     EMR       $94.57
Advanced Micro Devices   AMD       $84.51
Apple                    AAPL      $121.73
*/