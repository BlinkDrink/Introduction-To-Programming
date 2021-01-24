#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

const short MAX = 3000;

void insertElement(int arr[], int &size, int repeating, int sum, int index)
{
    for (int j = 0; j < repeating - 1; j++)
    {
        for (int i = index + 1; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }
    arr[index] = sum;
}

int main()
{
    int N, repeating = 2, sum = 0;
    cin >> N;
    int arr[MAX];
    if (N > 3000)
    {
        cout << "Error";
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] > 0)
            sum += arr[i];
    }

    for (int i = 0; i < N - 2; i++)
    {
        int startingIndex;
        while (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2] && i < N - 2)
        {
            if (repeating == 2)
            {
                startingIndex = i;
            }

            repeating++;
            i++;
        }
        if (repeating >= 3)
        {
            insertElement(arr, N, repeating, sum, startingIndex);
        }

        repeating = 2;
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}