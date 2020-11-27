#include <iostream>
#include <math.h>
using namespace std;

const int MAX_SIZE = 500;

bool InsertElement(int arr[], int& size, int index, int element)
{
	if (size + 1 <= MAX_SIZE && index < size)
	{
		for (int i = size; i > index; i--)
		{
			swap(arr[i], arr[i - 1]);
		}

		arr[index] = element;
		size++;
		return true;
	}
	return false;
}

int main()
{
	int size;
	cin >> size;

	int arr[MAX_SIZE];

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	int avg;

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			avg = (arr[i] + arr[i + 1]) / 2;
			InsertElement(arr, size, i + 1, avg);
			i++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}