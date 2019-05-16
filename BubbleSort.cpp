/*a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 6
implementation for the BubbleSort class*/
#include <fstream>
#include <iostream>
#include <string>
#include "BubbleSort.h"

#include <ctime>
#include <chrono>


using namespace std;
/*
a. BubbleSort() - default constructor for the BubbleSort class
b. NA
c. none
d. no exceptions thrown
*/
BubbleSort::BubbleSort()
{
	//nothing needs to happen here
	//ifstream m_inputStream;
	//string m_fileName;
}
/*
a. BubbleSort(string fileName) - overloaded constructor for the BubbleSort class
b. NA
c. string fileName - a string that represents the fileName of the file that we are reading the information from
d. no exceptions thrown
*/
BubbleSort::BubbleSort(string fileName)
{
	m_fileName = fileName;
}
/*
a. BubbleSort(double* values,int length) - an overloaded constructor for the BubbleSort class ***only exists for testing***
b. NA
c. double* values - a double* value that represents the array of doubles that we are sorting | int length - an int value that represent the length of the double array that we are sorting
d. no exceptions thrown
*/
BubbleSort::BubbleSort(double* values, int length)
{
	m_values = values;
	m_length = length;
}
/*
a. ~BubbleSort() - destructor for the BubbleSort class
b. NA
c. none
d. no exceptions thrown
*/
BubbleSort::~BubbleSort()
{
	delete m_values;
}
/*
a. RunBubbleSort() - the main logic for file reading,timing, and setting up the sorting algorithm
b. long long - a value which represents the amount of time that was taken by the algorithm to sort the values
c. none
d. no exceptions thrown
*/
long long BubbleSort::RunBubbleSort()
{
	string numValuesString = "";
	int numValues;
	double runningTime;
	time_t startTime;
	m_inputStream.open(m_fileName); 	//open the inputstream
	getline(m_inputStream, numValuesString);	//take in the number of values that need to be sorted
	numValues = atoi(numValuesString.c_str());
	double* values= new double[numValues]; 	//create a double array to sort these values with
	auto start = chrono::high_resolution_clock::now(); 	//start the time to sort
	startTime = chrono::system_clock::to_time_t(start);
	cout << "Started Bubble Sort at " << ctime(&startTime);
	auto timerStart = chrono::high_resolution_clock::now();
	BubbleSortAlgorithm(m_values, m_length); 	//sort the values
	auto timerStop = chrono::high_resolution_clock::now(); 	//stop the time to sort
	auto duration = chrono::duration_cast<chrono::microseconds>(timerStop - timerStart);
	return duration.count();	//return the difference between the times
}
/*
a. BubbleSortAlgorithm() - the main logic for the actual BubbleSort algorithm
b. void
c. double* arr - a double* value that represents the array of double values that we are sorting | int size - an integer value which represents the size of the double values that we are sorting
d. no exceptions thrown
*/
void BubbleSort::BubbleSortAlgorithm(double* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if (arr[i] > arr[j])
			{
				Swap(arr, i, j);
			}
		}
	}
}
/*
a. Swap() - a helper function for swapping two double values
b. void
c. double* arr - a double* value that represents the double array whose values we are switching | int indx1 - an int value that represents the index of the first value we are switching | int indx2 - an int value that represents the index of the second value that we are switching
d. no exceptions thrown
*/
void BubbleSort::Swap(double* arr, int indx1, int indx2)
{
	double cup = arr[indx1];
	arr[indx1] = arr[indx2];
	arr[indx2] = cup;
}
