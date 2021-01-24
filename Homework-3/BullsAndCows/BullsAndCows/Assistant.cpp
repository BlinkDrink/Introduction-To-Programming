#include "BullsAndCows.h"
#include <iostream>

using std::nothrow;

void getBullsAndCows(unsigned guess, unsigned answer, unsigned* bulls, unsigned* cows)
{
	unsigned posGuess = 0;

	while (guess > 0)
	{
		unsigned tmpAnswer = answer;
		unsigned posAnswer = 0;

		while (tmpAnswer > 0)
		{
			if (guess % 10 == tmpAnswer % 10)
			{
				if (posGuess == posAnswer)
				{
					(*bulls)++;
				}
				else
				{
					(*cows)++;
				}
				break;
			}
			tmpAnswer /= 10;
			posAnswer++;
		}

		guess /= 10;
		posGuess++;
	}
}

const int* tryGuess(int guess)
{
	static unsigned answer = 2468;

	int* resp = new (nothrow) int[2];
	if (!resp)
	{
		delete[] resp;
		return nullptr;
	}

	unsigned bulls = 0;
	unsigned cows = 0;

	getBullsAndCows(guess, answer, &bulls, &cows);

	resp[0] = bulls;
	resp[1] = cows;

	return resp;
}