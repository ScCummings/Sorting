/*a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 6
Header file for the Insertion Sort class.*/
#ifndef INSERTION_SORT
#define INSERTION_SORT
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class InsertionSort
{
private:
	ifstream m_inputStream;
	string m_fileName;
	int m_length;
	double* m_values = new double[m_length];
public:
	InsertionSort();
	InsertionSort(string fileName);
	InsertionSort(double* values, int length); //for testing only
	~InsertionSort();
	long long RunInsertionSort();
	void InsertionSortAlgorithm(double* arr, int size);
};
#endif //INSERTION_SORT
