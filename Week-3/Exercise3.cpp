#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете програма, която получава един символ от клавиатурата. 
Ако символа е цифра, да се изведе на екрана квадрата й. 
Ако е малка буква, да се изведе съответстващата й главна и обратно.
В противен случай, да се изведе символа непроменен.
*/

int main()
{
    char symbol;
    cin >> symbol;
    int charAsInt = (int)symbol;

    const int ONE_ASCII = 49;
    const int NINE_ASCII = 57;

    // Uppercase
    const int A_ASCII = 65;
    const int Z_ASCII = 90;

    // Lowercase
    const int LC_A_ASCII = 97;
    const int LC_Z_ASCII = 122;

    if (charAsInt >= ONE_ASCII & charAsInt <= NINE_ASCII)
    {
        cout << (charAsInt - (ONE_ASCII - 1)) * (charAsInt - (ONE_ASCII - 1));
    }
    else if (charAsInt >= A_ASCII & charAsInt <= Z_ASCII)
    {
        cout << (char)(charAsInt + LC_A_ASCII - A_ASCII);
    }
    else if (charAsInt >= LC_A_ASCII & charAsInt <= LC_Z_ASCII)
    {
        cout << (char)(charAsInt - (LC_A_ASCII - A_ASCII));
    }
    else
    {
        cout << symbol;
    }

    return 0;
}