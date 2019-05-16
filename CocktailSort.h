/*a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 6
header file for the CocktailSort class*/
#ifndef COCKTAIL_SORT
#define COCKTAIL_SORT
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class CocktailSort
{
private:
	ifstream m_inputStream;
	string m_fileName;
	double* m_values;
	int m_length;
public:
	CocktailSort();
	CocktailSort(string fileName);
	CocktailSort(double* values, int length);
	~CocktailSort();
	long long RunCocktailSort();
	void CocktailSortAlgorithm(double* arr, int size);
	void Swap(double* arr, int indx1, int indx2);
};
#endif //COCKTAIL_SORT
