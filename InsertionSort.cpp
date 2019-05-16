/*a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 6
implementation for the InsertionSort class*/
#include "InsertionSort.h"

#include <ctime>
#include <chrono>

using namespace std;
/*
a. InsertionSort() - default constructor for the InsertionSort class
b. NA
c. none
d. no exceptions thrown
*/
InsertionSort::InsertionSort()
{
	//nothing needs to happen here
}
/*
a. InsertionSort(string fileName) - overloaded constructor for the InsertionSort class
b. NA
c. string fileName - a string value that represents the fileName of the file whose double values we are sorting
d. no exceptions thrown
*/
InsertionSort::InsertionSort(string fileName)
{
	m_fileName = fileName;
}
/*
a. InsertionSort(double* values,int length) - overloaded constructor for the InsertionSort class ***only for testing***
b. NA
c. double* values - a double* value that represents the array of double values that we are sorting | int length - an int value that represents the length of the array that we are sorting
d. no exceptions thrown
*/
InsertionSort::InsertionSort(double* values, int length)
{
	m_values = values;
	m_length = length;
}
/*
a. ~InsertionSort() - destructor for the InsertionSort class
b. NA
c. none
d. no exceptions thrown
*/
InsertionSort::~InsertionSort()
{
	delete m_values;
}
/*
a. RunInsertionSort() - main logic for filereading, timing, and preparing the algorithm for sorting
b. long long - a value which represents the amount of time it took for the algorithm to sort
c. none
d. no exceptions thrown
*/
long long InsertionSort::RunInsertionSort()
{
	string numValuesString = "";
	int numValues;
	double runningTime;
	time_t startTime;
	m_inputStream.open(m_fileName); 	//open the inputstream
	getline(m_inputStream, numValuesString); 	//take in the number of values that need to be sorted
	numValues = atoi(numValuesString.c_str());
	double* values = new double[m_length]; 	//create a double array to sort these values with
	auto start = chrono::high_resolution_clock::now(); 	//start the time to sort
	startTime = chrono::system_clock::to_time_t(start);
	cout << "Started Insertion Sort at " << ctime(&startTime);
	auto timerStart = chrono::high_resolution_clock::now();
	InsertionSortAlgorithm(m_values, m_length); 	//sort the values
	auto timerStop = chrono::high_resolution_clock::now(); 	//stop the time to sort
	auto duration = chrono::duration_cast<chrono::microseconds>(timerStop - timerStart); 	//return the difference between the times
	return duration.count();
}
/*
a. InsertionSortAlgorithm() - the main logic for the actual InsertionSort algorithm
b. void
c. double* arr - a double* value that represents the array of double values that we are sorting | int size - an integer value which represents the size of the double values that we are sorting
d. no exceptions thrown
*/
void InsertionSort::InsertionSortAlgorithm(double* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		double key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
