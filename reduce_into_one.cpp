// https://www.geeksforgeeks.org/reduce-a-number-to-1-by-performing-given-operations/

// C++ program for the above approach
#include <iostream>
using namespace std;

int countSteps(int n)
{
	int count = 0;
	while (n > 1) {
		count++;

		// num even, divide by 2
		if (n % 2 == 0)
			n /= 2;

		// num odd, n%4 == 1
		// or n==3(special edge case),
		// decrement by 1
		else if (n % 4 == 1||n==3)
			n -= 1;

		// num odd, n%4 == 3, increment by 1
		else
			n += 1;
	}

	return count;
}

// driver code

int main()
{
	int n = 15;

	// Function call
	cout << countSteps(n) << "\n";

	return 0;
}


