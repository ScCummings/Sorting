/*a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 6
Header file for the QuickSort class*/
#include "QuickSort.h"
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;
/*
a. QuickSort() - default constructor for the QuickSort class
b. NA
c. none
d. no exceptions thrown
*/
QuickSort::QuickSort()
{
	//nothing needs to happen here
}
/*
a. QuickSort(string fileName) - overloaded constructor for the QuickSort class
b. NA
c. string fileName - a string value that represents the fileName of the file whose double values we are sorting
d. no exceptions thrown
*/
QuickSort::QuickSort(string fileName)
{
	m_fileName = fileName;
}
/*
a. QuickSort(double* values,int length) - overloaded constructor for the QuickSort class ***only for testing***
b. NA
c. double* values - a double* value that represents the array of double values that we are sorting | int length - an int value that represents the length of the array that we are sorting
d. no exceptions thrown
*/
QuickSort::QuickSort(double* values, int length) //just for testing
{
	m_length = length;
	m_values = values;
}
/*
a. ~QuickSort() - destructor for the QuickSort class
b. NA
c. none
d. no exceptions thrown
*/
QuickSort::~QuickSort()
{
	//nothing needs to happen here
}
/*
a. RunQuickSort() - main logic for filereading, timing, and preparing the algorithm for sorting
b. long long - a value which represents the amount of time it took for the algorithm to sort
c. none
d. no exceptions thrown
*/
long long QuickSort::RunQuickSort()
{
	string numValuesString = "";
	int numValues = m_length;
	double runningTime;
	time_t startTime;
	m_inputStream.open(m_fileName); 	//open the inputstream
	getline(m_inputStream, numValuesString); 	//take in the number of values that need to be sorted
	numValues = atoi(numValuesString.c_str());
	double* values = new double[numValues]; 	//create a double array to sort these values with
	auto start = chrono::high_resolution_clock::now(); 	//start the time to sort
	startTime = chrono::system_clock::to_time_t(start);
	cout << "Started Quick Sort at " << ctime(&startTime);
	auto timerStart = chrono::high_resolution_clock::now();
	QuickSortAlgorithm(m_values,0, numValues-1); 	//sort the values
	auto timerStop = chrono::high_resolution_clock::now(); 	//stop the time to sort
	auto duration = chrono::duration_cast<chrono::microseconds>(timerStop - timerStart); 	//return the difference between the times
	return duration.count();
}
/*
a. Partion() - a helper function that partions the data based on the location of the pivot
b. int - an integer value that represents the index of where the new partition should be located
c. double* arr - the double array that we are sorting | int low - the starting index | int high - the ending index
d. no exceptions thrown
*/
int QuickSort::Partition(double* arr, int low, int high)
{
	double pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;

			Swap(arr,i,j);
		}
	}
	Swap(arr,i + 1,high);
	return (i + 1);
}
/*
a. QuickSortAlgorithm() - the main logic for the actual QuickSort algorithm
b. void
c. double* arr - a double* value that represents the array of double values that we are sorting | int size - an integer value which represents the size of the double values that we are sorting
d. no exceptions thrown
*/
void QuickSort::QuickSortAlgorithm(double* arr, int low, int high)
{
	if (low < high)
	{
		int pi = Partition(arr, low, high);

		QuickSortAlgorithm(arr, low, pi - 1);
		QuickSortAlgorithm(arr, pi + 1, high);
	}
}
/*
a. Swap() - a helper function for swapping two double values
b. void
c. double* arr - a double* value that represents the double array whose values we are switching | int indx1 - an int value that represents the index of the first value we are switching | int indx2 - an int value that represents the index of the second value that we are switching
d. no exceptions thrown
*/
void QuickSort::Swap(double* arr, int indx1, int indx2)
{
	double cup = arr[indx1];
	arr[indx1] = arr[indx2];
	arr[indx2] = cup;
}
