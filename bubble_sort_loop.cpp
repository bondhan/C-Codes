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
	unsigned int k = 0;
	unsigned int l = v.size()-1;
	while(true)
	{
		while (l > k)
		{
			if (!isDescending)
			{
				if (v.at(k) > v.at(k+1))
				{
					//swap
					swap(v[k], v[k+1]);

				}
			}
			else
			{
				if (v.at(k) < v.at(k+1))
				{
					//swap
					swap(v[k], v[k+1]);

				}
			}
			k++;
		}
		l--;
		k = 0;

		if (l == 0)
			break;
	}
}

int main()
{

	cout << "Bubble Sort Loop" << endl;


	vector <int> array_data;
	fillVector(array_data, MAX_SIZE);
	printVector("Before Sort: ", array_data);

	doBubbleSort(array_data, false);
	printVector("ASC Sort: ", array_data);

	doBubbleSort(array_data, true);
	printVector("DESC Sort: ", array_data);

	return 0;
}


