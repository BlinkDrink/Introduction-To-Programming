#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
*Задача 5
Да се изведат първите 20 естествени числа, двоичния запис на които съдържа равен брой 0 и 1.
*/
bool binaryHasEqualZeroesAndOnes(int n)
{
    unsigned i;
    unsigned sumOfOnes = 0;
    unsigned sumOfZeroes = 0;

    if (n < 16)
    {
        for (i = 1 << 3; i > 0; i = i / 2)
            (n & i) ? sumOfOnes++ : sumOfZeroes++;
    }
    else
    {
        for (i = 1 << 7; i > 0; i = i / 2)
            (n & i) ? sumOfOnes++ : sumOfZeroes++;
    }

    return sumOfOnes == sumOfZeroes;
}

int main()
{
    int n = 20;

    for (int i = 1; i <= n; i++)
    {
        binaryHasEqualZeroesAndOnes(i) ? cout << i << " " : cout << "";
    }
}