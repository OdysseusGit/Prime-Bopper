/*
Novel implementation of the unique factorisation of prime numbers to output humorous sequences of nonsense.
*/

#include <iostream>
#include <cmath> //import sqrt function

using namespace std;

string bopString[] = {"beep", "boop", "bip", "bop", "bing", "bong", "blam", "blom", "wham", "bam", "thank-you", "ma'am"};

void bopper(int number);
void loopBop(int number);
bool isPrime(int number);

int main()
{
	int number;

	cout << "Enter your number:" << endl;
	cin >> number;

	bopper(number);
	//loopBop(number);

	return 0;
}

void bopper(int number)
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

void loopBop(int number)
{
	for(int i = 2; i <= number; i++)
	{
		bopper(i);
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
