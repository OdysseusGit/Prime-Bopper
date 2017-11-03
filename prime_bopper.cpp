/*
Novel implementation of the unique factorisation of prime numbers to output humorous sequences of nonsense.
*/

#include <iostream>
#include <cmath> //import sqrt function

using namespace std;

string bopString[] = {"beep", "boop", "bip", "bop", "bing", "bong", "blam", "blom", "wham", "bam", "thank-you", "ma'am"};

void beeper(int number);
void loopBeep(int number);
bool isPrime(int prime);

int main()
{
	int number;

	cout << "Enter your number:" << endl;
	cin >> number;

	beeper(number);
	//loopBeep(number);

	return 0;
}

void beeper(int number)
{
	int primeCounter = 0;
	string primeBopString[number + 1];

	for(int i = 2; i <= number; i++)
	{
		if(isPrime(i))
		{
			//sizeof gives size of array in bytes
			if(primeCounter >= sizeof(bopString)/sizeof(*bopString))
			{
				primeBopString[i] = "aling";
			}
			else
			{
				primeBopString[i] = bopString[primeCounter];
				primeCounter++;
			}

			while(number % i == 0)
			{
				cout << primeBopString[i];
				number = number/i;
			}

		}
	}

	cout << endl;
}

void loopBeep(int number)
{
	for(int i = 2; i <= number; i++)
	{
		beeper(i);
	}
}

bool isPrime(int number)
{
	if(number <= 1)
	{
		return false;
	}

	for(int i = 2; i <= sqrt(number); i++)
	{
		if(number % i == 0)
		{
			return false;
		}
	}

	return true;
}
