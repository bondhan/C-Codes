//============================================================================
// Name        : Insertion_Sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

#define MAX_VALUE 20
#define MAX_SIZE 20

template <class T>
void printVector(const char *msg, T &v)
{
	cout << msg << endl;

	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}

	cout <<endl;
}

template <class T>
void fillVector(T &v, int size)
{
	srand(time(NULL));

	for (int k = 0; k < size; k++)
	{
		v.push_back(rand() % MAX_VALUE);
	}
}

template <class T>
void doInsertionSort(T &v, bool isDescending)
{
	unsigned int j = 0;
	for (unsigned int i = 1; i < v.size(); i++)
	{
		j = i;
		while (j > 0)
		{
			if (v.at(j) < v.at(j-1) && !isDescending)
			{
				swap(v[j], v[j-1]);
			}
			else if (v.at(j) > v.at(j-1) && isDescending)
			{
				swap(v[j], v[j-1]);
			}
			j--;
		}
	}

}

int main()
{
	cout << "Insertion Sort" << endl;

	vector <int> array_data;
	fillVector(array_data, MAX_SIZE);
	printVector("Before Sort: ", array_data);

	doInsertionSort(array_data, false);
	printVector("ASC Sort: ", array_data);

	doInsertionSort(array_data, true);
	printVector("DESC Sort: ", array_data);

}
