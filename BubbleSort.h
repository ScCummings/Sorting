/*a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 6
header file for the BubbleSort class*/
#ifndef BUBBLE_SORT
#define BUBBLE_SORT
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class BubbleSort
{
private:
	ifstream m_inputStream;
	string m_fileName;
	double* m_values;
	int m_length;
public:
	BubbleSort();
	BubbleSort(string fileName);
	BubbleSort(double* values, int length);
	~BubbleSort();
	long long RunBubbleSort();
	void Swap(double* arr, int indx1, int indx2);
	void BubbleSortAlgorithm(double* arr, int size);
};
#endif //BUBBLE_SORT
