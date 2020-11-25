#include <iostream>
#include <cmath>

// Купили сте си Биткойн и има промяна в цената му. Напишете програма която по подадени положително
// число с плаваща запетая - колко биткойн имате и число с плаваща запетая в граници [-100, 100] -
// промяната на биткойн в проценти изчислява и отпечатва новата сума биткойн която притежавате след
// промяната в цената и разликата между старата и новата сума.

int main()
{
    float bitcoins, percentage, change;
    std::cin >> bitcoins >> percentage;

    change = bitcoins;
    bitcoins += (percentage * bitcoins) / 100;
    change = change - bitcoins;

    if (percentage < 0)
        change = -change;

    std::cout
        << "You now have " << bitcoins << " bitcoins!" << std::endl;
    std::cout << "The change in your balance is " << change << ".";

    return 0;
}
