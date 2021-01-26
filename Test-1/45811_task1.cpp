#include <iostream>

using std::cin;
using std::cout;

//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Контролно 1
// 2020-11-29
//
// Начален час на контролното: 9:00
// Име: Петко Иванов Петков
// ФН: 45811
// Специалност: Информатика
// Курс: 1
// Административна група: 5
// Използван компилатор: mingw-w64
//

int main()
{
    bool bin11, bin12, bin13, bin14;
    bool bin21, bin22, bin23, bin24;
    bool conversion = 0;

    cin >> bin14 >> bin13 >> bin12 >> bin11;
    cin >> bin24 >> bin23 >> bin22 >> bin21;

    bool resBin1, resBin2, resBin3, resBin4;
    resBin1 = bin11 ^ bin21 ^ conversion;
    conversion = (bin11 & bin21) || (bin11 & conversion) || (bin21 & conversion);

    resBin2 = bin12 ^ bin22 ^ conversion;
    conversion = (bin12 & bin22) || (bin12 & conversion) || (bin22 & conversion);

    resBin3 = bin13 ^ bin23 ^ conversion;
    conversion = (bin13 & bin23) || (bin13 & conversion) || (bin23 & conversion);

    resBin4 = bin14 ^ bin24 ^ conversion;
    conversion = (bin14 & bin24) || (bin14 & conversion) || (bin24 & conversion);

    cout << conversion << resBin4 << resBin3 << resBin2 << resBin1;

    return 0;
}