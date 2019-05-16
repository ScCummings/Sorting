/*a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 6
implementation for the CocktailSort class*/
#include "CocktailSort.h"

#include <ctime>
#include <chrono>

using namespace std;
/*
a. CocktailSort() - default constructor for the CocktailSort class
b. NA
c. none
d. no exceptions thrown
*/
CocktailSort::CocktailSort()
{
	//nothing needs to happen here
}
/*
a. CocktailSort(string fileName) - overloaded constructor for the CocktailSort class
b. NA
c. string fileName - a string value that represents the fileName of the file whose double values we are sorting
d. no exceptions thrown
*/
CocktailSort::CocktailSort(string fileName)
{
	m_fileName = fileName;
}
/*
a. CocktailSort(double* values,int length) - overloaded constructor for the CocktailSort class ***only for testing***
b. NA
c. double* values - a double* value that represents the array of double values that we are sorting | int length - an int value that represents the length of the array that we are sorting
d. no exceptions thrown
*/
CocktailSort::CocktailSort(double* values, int length)
{
	m_values = values;
	m_length = length;
}
/*
a. ~CocktailSort() - destructor for the CocktailSort class
b. NA
c. none
d. no exceptions thrown
*/
CocktailSort::~CocktailSort()
{
	delete m_values;
}
/*
a. RunCocktailSort() - main logic for filereading, timing, and preparing the algorithm for sorting
b. long long - a value which represents the amount of time it took for the algorithm to sort
c. none
d. no exceptions thrown
*/
long long CocktailSort::RunCocktailSort()
{
	string numValuesString = "";
	int numValues;
	double runningTime;
	time_t startTime;
	m_inputStream.open(m_fileName);		//open the inputstream
	getline(m_inputStream, numValuesString);	 //take in the number of values that need to be sorted
	numValues = atoi(numValuesString.c_str());
	double* values = new double[numValues]; 	//create a double array to sort these values with
	auto start = chrono::high_resolution_clock::now();	 //start the time to sort
	startTime = chrono::system_clock::to_time_t(start);
	cout << "Started Cocktail Sort at " << ctime(&startTime);
	auto timerStart = chrono::high_resolution_clock::now();
	CocktailSortAlgorithm(m_values, m_length); 	//sort the values
	auto timerStop = chrono::high_resolution_clock::now(); 	//stop the time to sort
	auto duration = chrono::duration_cast<chrono::microseconds>(timerStop - timerStart); 	//return the difference between the times
	return duration.count();
}
/*
a. CocktailSortAlgorithm() - the main logic for the actual CocktailSort algorithm
b. void
c. double* arr - a double* value that represents the array of double values that we are sorting | int size - an integer value which represents the size of the double values that we are sorting
d. no exceptions thrown
*/
void CocktailSort::CocktailSortAlgorithm(double* arr, int size)
{
	bool swapped = true;
	int start = 0;
	int end = size - 1;
	while (swapped)
	{
		swapped = false;
		for (int i = start; i < end - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				Swap(arr, i, i+1);
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
		swapped = false;
		--end;
		for (int j = end; j >= start; --j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr, j, j+1);
				swapped = true;
			}
		}
		++start;
	}
}
/*
a. Swap() - a helper function for swapping two double values
b. void
c. double* arr - a double* value that represents the double array whose values we are switching | int indx1 - an int value that represents the index of the first value we are switching | int indx2 - an int value that represents the index of the second value that we are switching
d. no exceptions thrown
*/
void CocktailSort::Swap(double* arr, int indx1, int indx2)
{
	double cup = arr[indx1];
	arr[indx1] = arr[indx2];
	arr[indx2] = cup;
}
