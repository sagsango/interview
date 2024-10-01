/* 2 sum problem : https://www.techiedelight.com/find-pair-with-given-sum-array/     */
/* this is a window problem not 2 pointers */
Using Sorting
The idea is to sort the given array in ascending order and maintain search space
by maintaining two indices (low and high) that initially points to two endpoints 
of the array. Then reduce the search space nums[low…high] at each iteration of the 
loop by comparing the sum of elements present at indices low and high with the 
desired sum. Increment low if the sum is less than the expected sum; otherwise,
decrement high if the sum is more than the desired sum. If the pair is found, return it.

Following is the C++, Java, and Python implementation based on the idea:

#include <iostream>
#include <algorithm>
using namespace std;
 
// Function to find a pair in an array with a given sum using sorting
void findPair(int nums[], int n, int target)
{
    // sort the array in ascending order
    sort(nums, nums + n);
 
    // maintain two indices pointing to endpoints of the array
    int low = 0;
    int high = n - 1;
 
    // reduce the search space `nums[low…high]` at each iteration of the loop
 
    // loop till the search space is exhausted
    while (low < high)
    {
        // sum found
        if (nums[low] + nums[high] == target)
        {
            cout << "Pair found (" << nums[low] << ", " << nums[high] << ")\n";
            return;
        }
 
        // increment `low` index if the total is less than the desired sum;
        // decrement `high` index if the total is more than the desired sum
        (nums[low] + nums[high] < target)? low++: high--;
    }
 
    // we reach here if the pair is not found
    cout << "Pair not found";
}
 
int main()
{
    int nums[] = { 8, 7, 2, 5, 3, 1 };
    int target = 10;
 
    int n = sizeof(nums)/sizeof(nums[0]);
 
    findPair(nums, n, target);
 
    return 0;
}
