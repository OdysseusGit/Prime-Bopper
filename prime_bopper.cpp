/*
Novel implementation of the unique factorisation of prime numbers to output humorous sequences of nonsense.
*/

#include <iostream>
#include <string>
#include <cmath> //import sqrt function

std::string bopString[] = { "beep", "boop", "bip", "bop", "bing", "bong", "blam", "blom", "wham", "bam", "thank-you", "ma'am" };

void bopper(int number);
void loopBop(int number);
bool isPrime(int number);

int main()
{
	bool done = false;
	while (!done)
	{
		std::string inputString;
		std::cout << "Enter your number:" << std::endl;
		std::cin >> inputString;

		if (inputString == "quit")
		{
			done = true;
		}
		else
		{
			bopper(stoi(inputString));
			//loopBop(stoi(inputString));
		}
	}

	return 0;
}

void bopper(int number)
{
	int primeCounter = 0;

	for (int i = 2; i <= number; i++)
	{
		if (isPrime(i))
		{
			std::string outputString;

			//sizeof gives size of array in bytes
			if (primeCounter >= sizeof(bopString) / sizeof(*bopString))
			{
				outputString = "aling";
			}
			else
			{
				outputString = bopString[primeCounter];
				primeCounter++;
			}

			while (number % i == 0)
			{
				std::cout << outputString;
				number = number / i;
			}
		}
	}

	std::cout << std::endl;
}

void loopBop(int number)
{
	for (int i = 2; i <= number; i++)
	{
		bopper(i);
	}
}

bool isPrime(int number)
{
	if (number <= 1)
	{
		return false;
	}

	//small optimisation to better mimic Eratosthenes' sieve
	if (number % 2 == 0 && 2 <= sqrt(number))
	{
		return false;
	}

	for (int i = 3; i <= sqrt(number); i += 2)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}
