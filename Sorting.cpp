/*a. Scott Cummings
b. 2317991
c. scummings@chapman.edu
d. CPSC 350 - Section 1
e. Assignment 6
Main driver class of the program*/
#include "BubbleSort.h"
#include "CocktailSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include <random>
#include <string>
using namespace std;
bool fileExists(string fileName);
int main(int argc,char* argv[])
{
    if(argc = 0)
    {
        cout << "Please enter in your file name as a command line argument" << endl;
        exit(0);
    }
    string fileName((*argv));
    if(!fileExists(fileName))
    {
        cout << "Sorry, we couldn't find that file name." << endl;
        exit(0);
    }
    int userResponse;
    cout << "Which sort would you like to perform?\n Quick Sort (1)\n Insertion Sort (2)\n Bubble Sort (3)\n Cocktail Sort (4)" << endl;
    cin >> userResponse;
    switch(userResponse)
    {
        case 1:
        {
            //Make and Run QuickSort
            QuickSort* quickSort = new QuickSort(fileName);
            cout << "Time taken by quick sort: " << quickSort->RunQuickSort() << endl;
            break;
        }
        case 2:
        {
            //Make and Run InsertionSort
            InsertionSort* insertionSort = new InsertionSort(fileName);
            cout << "Time taken by insertion sort: " << insertionSort->RunInsertionSort() << endl;
            break;
        }
        case 3:
        {
            //Make and Run Bubble Sort
            BubbleSort* bubbleSort = new BubbleSort(fileName);
            cout << "Time taken by bubble sort: " << bubbleSort->RunBubbleSort() << endl;
            break;
        }
        case 4:
        {
            //Make and Run CocktailSort
            CocktailSort* cocktailSort = new CocktailSort(fileName);
            cout << "Time taken by cocktail sort: " << cocktailSort->RunCocktailSort() << endl;
            break;
        }
        default:
            cout << "Sorry, input not recognized." << endl;
            break;
    }
    cout << "Thank you for coming!" << endl;
    return 0;
}
/*
a. fileExists
b. @return - a boolean representing whether or not the file that the user passed in exists.
c. @param - a string value that represents the filename that the user passed in.
d. No exceptions thrown.
*/
bool fileExists(string filename)
{
	ifstream f(filename.c_str());
	return f.good();
}
