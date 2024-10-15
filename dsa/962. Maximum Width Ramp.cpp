/*
https://leetcode.com/problems/maximum-width-ramp/editorial/


A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

 

Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
 

Constraints:

2 <= nums.length <= 5 * 104
0 <= nums[i] <= 5 * 104
*/

// M1:
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maxWidth = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] <= nums[j]) {
                    maxWidth = max(maxWidth, j - i);
                }
            }
        }
        return maxWidth;
    }
};


//M2:
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);

        // Initialize the array with indices
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // Sort indices based on corresponding values in nums and ensure
        // stability
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        });

        int minIndex = n;  // Minimum index encountered so far
        int maxWidth = 0;

        // Calculate maximum width ramp
        for (int i = 0; i < n; i++) {
            maxWidth = max(maxWidth, indices[i] - minIndex);
            minIndex = min(minIndex, indices[i]);
        }

        return maxWidth;
    }
};

//M3:
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);

        // Fill rightMax array with the maximum values from the right
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int left = 0, right = 0;
        int maxWidth = 0;

        // Traverse the array using left and right pointers
        while (right < n) {
            // Move left pointer forward if current left exceeds rightMax
            while (left < right && nums[left] > rightMax[right]) {
                left++;
            }
            maxWidth = max(maxWidth, right - left);
            right++;
        }

        return maxWidth;
    }
};

//M4:
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> indicesStack;

        // Fill the stack with indices in increasing order of their values
        for (int i = 0; i < n; i++) {
            if (indicesStack.empty() || nums[indicesStack.top()] > nums[i]) {
                indicesStack.push(i);
            }
        }

        int maxWidth = 0;

        // Traverse the array from the end to the start
        for (int j = n - 1; j >= 0; j--) {
            while (!indicesStack.empty() &&
                   nums[indicesStack.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - indicesStack.top());
                // Pop the index since it's already processed
                indicesStack.pop();
            }
        }

        return maxWidth;
    }
};






