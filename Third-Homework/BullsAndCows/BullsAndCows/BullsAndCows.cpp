#include "BullsAndCows.h"
#include <iostream>

using std::cout;

void play();
bool isValidNumber(unsigned);
void populateValidNumsArr(unsigned*);
void optimizeValidNumsArr(unsigned, unsigned*&, unsigned&, const int*);
void getBullsAndCowsResponse(unsigned, unsigned, unsigned*, unsigned*);
unsigned getValidNumbersCnt();

void play()
{
	unsigned validNumbersCnt = getValidNumbersCnt();
	unsigned* validNumsArr = new (std::nothrow) unsigned[validNumbersCnt];
	if (!validNumsArr)
	{
		delete[] validNumsArr;
		return;
	}

	unsigned tries = 1;
	unsigned maxTries = 7;
	populateValidNumsArr(validNumsArr);

	while (tries <= maxTries)
	{
		unsigned currentGuess = validNumsArr[0];

		const int* response = tryGuess(currentGuess);

		if (response[0] == 4 && response[1] == 0)
		{
			cout << "The program won in " << tries << " tries.";
			delete[] validNumsArr;
			return;
		}
		else
		{
			optimizeValidNumsArr(currentGuess, validNumsArr, validNumbersCnt, response);
		}

		tries++;
	}

	cout << "The program lost :(.";
	delete[] validNumsArr;
}

unsigned getValidNumbersCnt()
{
	unsigned cnt = 0;

	for (int i = 1234; i <= 9876; i++)
	{
		if (isValidNumber(i))
		{
			cnt++;
		}
	}

	return cnt;
}

bool isValidNumber(unsigned num)
{
	unsigned numCpy = num;
	unsigned numCpySnd = num;

	while (num != 0)
	{
		unsigned numLastDig = num % 10;
		if (numLastDig == 0)
		{
			return false;
		}
		unsigned repeatedCnt = 0;

		while (numCpy != 0)
		{
			if (numLastDig == numCpy % 10)
			{
				repeatedCnt++;
			}

			numCpy /= 10;
		}

		if (repeatedCnt > 1)
		{
			return false;
		}

		num /= 10;
		numCpy = numCpySnd;
	}

	return true;
}

void populateValidNumsArr(unsigned* arr)
{
	unsigned arrInd = 0;
	for (int i = 1234; i <= 9876; i++)
	{
		if (isValidNumber(i))
		{
			arr[arrInd++] = i;
		}
	}
}

void getBullsAndCowsResponse(unsigned guess, unsigned answer, unsigned* bulls, unsigned* cows)
{
	unsigned guessIndex = 0;

	while (guess > 0)
	{
		unsigned answerCpy = answer;
		unsigned answerIndex = 0;

		while (answerCpy > 0)
		{
			if (guess % 10 == answerCpy % 10)
			{
				if (guessIndex == answerIndex)
				{
					(*bulls)++;
				}
				else
				{
					(*cows)++;
				}
				break;
			}
			answerCpy /= 10;
			answerIndex++;
		}

		guess /= 10;
		guessIndex++;
	}
}

void optimizeValidNumsArr(unsigned guess, unsigned*& arr, unsigned& size, const int* response)
{
	unsigned bulls = 0;
	unsigned cows = 0;
	unsigned respBulls = response[0];
	unsigned respCows = response[1];

	unsigned validNumsCnt = 0;
	int resInd = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == guess)
		{
			continue;
		}

		getBullsAndCowsResponse(arr[i], guess, &bulls, &cows);

		if (respBulls == bulls && respCows == cows)
		{
			validNumsCnt++;
		}

		bulls = 0;
		cows = 0;
	}

	unsigned* result = new unsigned[validNumsCnt];
	if (!result)
	{
		delete[] result;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == guess)
		{
			continue;
		}

		getBullsAndCowsResponse(arr[i], guess, &bulls, &cows);

		if (respBulls == bulls && respCows == cows)
		{
			result[resInd++] = arr[i];
		}

		bulls = 0;
		cows = 0;
	}

	size = validNumsCnt;

	delete[] arr;
	arr = result;
}