// https://www.geeksforgeeks.org/count-of-triplets-in-an-array-i-j-k-such-that-i-j-k-and-ak-ai-aj/
/*
	 Count of triplets in an Array (i, j, k) such that i < j < k and a[k] < a[i] < a[j]

	 similar question:-
	 1. Find a number of triplets in an array A that satisfy the condition:  A[i] < A[j] < A[k] where i < k < jstion:


	 Time : O(n*n)

*/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count triplets
int CountTriplets(int a[], int n)
{

	// To store count of total triplets
	int ans = 0;

	for (int i = 0; i < n; i++) {

		// Initialize count to zero
		int cnt = 0;

		for (int j = i + 1; j < n; j++) {

			// If a[j] > a[i] then,
			// increment cnt
			if (a[j] > a[i])
				cnt++;

			// If a[j] < a[i], then
			// it mean we have found a[k]
			// such that a[k] < a[i] < a[j]
			else
				ans += cnt;
		}
	}

	// Return the final count
	return ans;
}

// Driver code
int main()
{
	int arr[] = { 2, 5, 1, 3, 0 };

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << CountTriplets(arr, n) << endl;

	return 0;
}


