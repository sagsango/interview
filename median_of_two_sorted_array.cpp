// https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/

/*
	 1. Lets assume that there are two arrays A and B with array A having the minimum number of elements.
	 		If this is not the case than swap A and B to make A having small size.
	 2. The edge cases like one array is empty or both are empty will be handled.
	 3. let n be the size of A and m be the size of B.
	 		Now think of an idea that if we have to find the median than we have to divide the whole merged array into two parts
	 		namely left and right parts.
	 		Now since we are given the size of left part (i.e (n+m+1)/2), Now look at below given example.

	 		A-> 1,2,3,4,5     n = 5
	 		B-> 1,2,3,4,5,6   m = 6

	 		Here merged array will look like :- 1,1,2,2,3,3,4,4,5,5,6 and median then is 3

	 		Now we can see our left part which is underlined. We divide A and B into two parts such that the
	 		sum of left part of both A and B will result in left part of merged array.

	 		A-> 1,2,3,4,5     // pointers l =0 and r = n-1 hence mid = (l+r)/2;
	 		B -> 1,2,3,4,5,6

	 		we can see that left part of A is given as n/2 and since total length of left part in merged array
	 		is (m+n+1)/2, so left part of B = (m+n+1)/2-n/2;

	 		Now we just have to confirm if our left and right partitions in A and B are correct or not.

	 4. Now we have 4 variables indicating four values two from array A and two from array B.
	 		leftA -> Rightmost element in left part of A = 2
	 		leftb -> Rightmost element in left part of B = 4
	 		rightA -> Leftmost element in right part of A = 3
	 		rightB -> Leftmost element in right part of B = 5

	 		Hence to confirm that partition is correct we have to check the following conditions.
	 		leftA<=rightB and leftB<=rightA  // This is the case when the sum of two parts of A and B results in left part of merged array

	 		if our partition not works that means we have to  find other mid point in A and then left part in B
	 		This is seen when

	 		leftA > rightB    //means we have to dec size of A's partition
	 		so do r = mid-1;
	 		else
	 		do l =mid+1;

	 		Hence repeat the above steps with new partitions till we get the answers.
	 5. If leftA<=rightB and leftB<=rightA
	 		then we get correct partition and our answer depends on the total size of merged array (i.e. m+n)

	 		If (m+n)%2==0
	 		ans is max(leftA,leftB)+min(rightA,rightB)/2; // max of left part is nearest to median and min of right part is nearest to medain
	 		else
	 		ans is max(leftA,leftB);

 */

#include <bits/stdc++.h>
using namespace std;

// Method to find median
double Median(vector<int>& A, vector<int>& B)
{
	int n = A.size();
	int m = B.size();
	if (n > m)
		return Median(B, A); // Swapping to make A smaller

	int start = 0;
	int end = n;
	int realmidinmergedarray = (n + m + 1) / 2;

	while (start <= end) {
		int mid = (start + end) / 2;
		int leftAsize = mid;
		int leftBsize = realmidinmergedarray - mid;
		int leftA
			= (leftAsize > 0)
			? A[leftAsize - 1]
			: INT_MIN; // checking overflow of indices
		int leftB
			= (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
		int rightA
			= (leftAsize < n) ? A[leftAsize] : INT_MAX;
		int rightB
			= (leftBsize < m) ? B[leftBsize] : INT_MAX;

		// if correct partition is done
		if (leftA <= rightB and leftB <= rightA) {
			if ((m + n) % 2 == 0)
				return (max(leftA, leftB)
						+ min(rightA, rightB))
					/ 2.0;
			return max(leftA, leftB);
		}
		else if (leftA > rightB) {
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return 0.0;
}

// Driver code
int main()
{
	vector<int> arr1 = { -5, 3, 6, 12, 15 };
	vector<int> arr2 = { -12, -10, -6, -3, 4, 10 };
	cout << "Median of the two arrays are" << endl;
	cout << Median(arr1, arr2);
	return 0;
}


