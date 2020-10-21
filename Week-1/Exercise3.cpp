#include <iostream>

// Изведете възрастта на която ще завършите ФМИ като въведете текущата си възраст от стандартния вход
// и я съберете с числото 7.

int main()
{
    int age;
    std::cin >> age;
    std::cout << "I will graduate from FMI when I am " << age + 7 << " years old.";

    return 0;
}
