#include <iostream>
#include <cmath>

/*
Вие сте хакери и искате да промените оценката си по УП с 3 единици нагоре
*/

int main()
{
    {
        int grade;
        std::cin >> grade;

        for (int i = 0; i < 3; i++)
        {
            grade = (-(~grade));
        }

        std::cout << grade;
    }
}