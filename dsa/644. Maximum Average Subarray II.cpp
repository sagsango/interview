/*
https://leetcode.com/problems/maximum-average-subarray-ii/description/

644. Maximum Average Subarray II
Hard

You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is greater than or equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation:
- When the length is 4, averages are [0.5, 12.75, 10.5] and the maximum average is 12.75
- When the length is 5, averages are [10.4, 10.8] and the maximum average is 10.8
- When the length is 6, averages are [9.16667] and the maximum average is 9.16667
The maximum average is when we choose a subarray of length 4 (i.e., the sub array [12, -5, -6, 50]) which has the max average 12.75, so we return 12.75
Note that we do not consider the subarrays of length < 4.

Example 2:
Input: nums = [5], k = 1
Output: 5.00000


Constraints:
n == nums.length
1 <= k <= n <= 104
-104 <= nums[i] <= 104

*/


class Solution {
    double findMaxAverage(vector<int>&nums, int k) {
        double max_val = MIN_VALUE;
        double min_val = MAX_VALUE;
        for (int n: nums) {
            max_val = max(max_val, n);
            min_val = min(min_val, n);
        }
        double prev_mid = max_val, error = MAX_VALUE;
        while (error > 0.00001) {
            double mid = (max_val + min_val) * 0.5;
            if (check(nums, mid, k))
                min_val = mid;
            else
                max_val = mid;
            error = abs(prev_mid - mid);
            prev_mid = mid;
        }
        return min_val;
    }
    oolean check(vector<int>&nums, double mid, int k) {
        double sum = 0, prev = 0, min_sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i] - mid;
        if (sum >= 0)
            return true;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            min_sum = min(prev, min_sum);
            if (sum >= min_sum)
                return true;
        }
        return false;
    }
}
