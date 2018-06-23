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
void doSelectionSort(T &v, bool isDescending)
{
	unsigned int k = 0;
	while(v.size() > k)
	{
		for(unsigned int j = k+1; j < v.size(); j++)
		{
			if (v.at(k) > v.at(j) && !isDescending)
			{
				swap(v[k], v[j]);
			}
			else if (v.at(k) < v.at(j) && isDescending)
			{
				swap(v[k], v[j]);
			}
		}
		k++;
	}
}

int main()
{
	cout << "Selection Sort" << endl;

	vector <int> array_data;
	fillVector(array_data, MAX_SIZE);
	printVector("Before Sort: ", array_data);

	doSelectionSort(array_data, false);
	printVector("ASC Sort: ", array_data);

	doSelectionSort(array_data, true);
	printVector("DESC Sort: ", array_data);

}
