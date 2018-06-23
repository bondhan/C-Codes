#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

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
void doBubbleSort(T &v, bool isDescending)
{
	bool wasSwapped = true;
	unsigned k = 0;
	while(wasSwapped)
	{
		wasSwapped = false;

		while (v.size()-1 > k )
		{
			if (!isDescending)
			{
				if (v.at(k) > v.at(k+1))
				{
					//swap
					swap(v[k], v[k+1]);
					wasSwapped = true;
				}
			}
			else
			{
				if (v.at(k) < v.at(k+1))
				{
					//swap
					swap(v[k], v[k+1]);
					wasSwapped = true;
				}
			}
			k++;
		}

		if ( k >= v.size() && wasSwapped == false)
		{
			break;
		}
		else
			k = 0;
	}
}

int main()
{
	cout << "Bubble Sort Bool" << endl;

	vector <int> array_data;
	fillVector(array_data, MAX_SIZE);
	printVector("Before Sort: ", array_data);

	doBubbleSort(array_data, false);
	printVector("ASC Sort: ", array_data);

	doBubbleSort(array_data, true);
	printVector("DESC Sort: ", array_data);

	return 0;
}


