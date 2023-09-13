// https://www.geeksforgeeks.org/the-celebrity-problem/


// Time O(n), space O(1)

// Java program to find celebrity
// in the given Matrix of people
// Code by Sparsh_cbs


/*

XXX:
The Celebrity Problem using Elimination Technique:
Some observations are based on elimination technique (Refer to Polya’s How to Solve It book). 

If A knows B, then A can’t be a celebrity. Discard A, and B may be celebrity.
If A doesn’t know B, then B can’t be a celebrity. Discard B, and A may be celebrity.
Repeat above two steps till there is only one person.
Ensure the remained person is a celebrity. (What is the need of this step?)

*/


import java.io.*;

class GFG {
	public static void main(String[] args)
	{
		int[][] M = { { 0, 0, 1, 0 },
					{ 0, 0, 1, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 1, 0 } };

		int celebIdx = celebrity(M, 4);

		if (celebIdx == -1)
			System.out.println("No celebrity found!");
		else {
			System.out.println(
				"0-based celebrity index is : " + celebIdx);
		}
	}
	public static int celebrity(int M[][], int n)
	{
		// This function returns the celebrity
		// index 0-based (if any)

		int i = 0, j = n - 1;
		while (i < j) {
			if (M[j][i] == 1) // j knows i
				j--;
			else // j doesnt know i so i cant be celebrity
				i++;
		}
		// i points to our celebrity candidate
		int candidate = i;

		// Now, all that is left is to check that whether
		// the candidate is actually a celebrity i.e: he is
		// known by everyone but he knows no one
		for (i = 0; i < n; i++) {
			if (i != candidate) {
				if (M[i][candidate] == 0
					|| M[candidate][i] == 1)
					return -1;
			}
		}
		// if we reach here this means that the candidate
		// is really a celebrity
		return candidate;
	}
}


