#include <iostream>

/*
Съставете булев израз, който по въведена година от стандартния вход, показва дали годината е високосна или не.

Пример: Вход: 2020 Изход: true Вход: 1900 Изход: false
*/

using std::cout;

int main()
{
    int year;
    std::cin >> year;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                cout << "true";
            else
                cout << "false";
        }
        else
            cout << "true";
    }
    else
        cout << "false";

    return 0;
}
