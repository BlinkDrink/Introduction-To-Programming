#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void FillArr(int arr[][MAX_SIZE], int n)
{
	for (int i = 0; i < n * n; i++)
	{
		for (int k = 0; k < n * n; k++)
		{
			cin >> arr[i][k];
		}
	}
}

bool IsNotRepeating(int arr[], int n)
{
	for (int i = 0; i < n * n; i++)
	{
		for (int j = i + 1; j < n * n; j++)
		{
			if (arr[i] == arr[j])
			{
				return false;
			}
		}
	}
	return true;
}

bool IsContaining(int arr[], int helpArr[], int n)
{
	for (int i = 0; i < n * n; i++)
	{
		bool contains = false;
		for (int j = 0; j < n * n; j++)
		{
			if (arr[i] == helpArr[j])
			{
				contains = true;
				break;
			}
		}
		if (!contains)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;

	int mat[MAX_SIZE][MAX_SIZE];

	FillArr(mat, n);

	int helperArr[MAX_SIZE];
	int ind = 1;
	for (int i = 0; i < n * n; i++)
	{
		helperArr[i] = ind++;
	}

	bool isSudoku = true;

	// checking rows
	for (int i = 0; i < n * n; i++)
	{
		if (!IsNotRepeating(mat[i], n) || !IsContaining(mat[i], helperArr, n))
		{
			isSudoku = false;
		}
	}

	int colArr[MAX_SIZE];
	// checking cols
	for (int i = 0; i < n * n; i++)
	{
		for (int j = 0; j < n * n; j++)
		{
			colArr[j] = mat[j][i];
		}

		if (!IsNotRepeating(colArr, n) || !IsContaining(colArr, helperArr, n))
		{
			isSudoku = false;
		}
	}

	// checking squares
	int subSq[MAX_SIZE][MAX_SIZE];
	int squareArr[MAX_SIZE];
	for (int i = 0; i < n * n; i += n)
	{
		for (int j = 0; j < n * n; j += n)
		{
			for (int k = i; k < i + n; k++)
			{
				for (int l = j; l < j + n; l++)
				{
					subSq[k][l] = mat[k][l];
				}
			}
			int index = 0;
			for (int ind1 = 0; ind1 < n; ind1++)
			{
				for (int ind2 = 0; ind2 < n; ind2++)
				{
					squareArr[index++] = subSq[ind1][ind2];
				}
			}
			if (!IsNotRepeating(squareArr, n) || !IsContaining(squareArr, helperArr, n))
			{
				isSudoku = false;
			}
		}
	}

	cout << (isSudoku ? "Yes" : "No") << endl;

	return 0;
}