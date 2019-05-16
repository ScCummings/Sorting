/*a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 6
Header file for the QuickSort class*/
#ifndef QUICK_SORT
#define QUICK_SORT
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class QuickSort
{
private:
	//the stream that we will get the doubles from
	ifstream m_inputStream;
	string m_fileName;
	double* m_values;
	int m_length;

public:
	QuickSort();
	QuickSort(string fileName);
	QuickSort(double* values, int length); //just for testing
	~QuickSort();
	long long RunQuickSort();
	void Swap(double* arr, int indx1, int indx2);
	int Partition(double* arr, int startingIndex, int endingIndex);
	void QuickSortAlgorithm(double* arr, int startingIndex, int endingIndex);

};
#endif //QUICK_SORT
