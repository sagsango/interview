/*
https://leetcode.com/problems/find-the-original-typed-string-ii/description/

3333. Find the Original Typed String II
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:
Input: word = "aabbccdd", k = 7
Output: 5
Explanation:
The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".

Example 2:
Input: word = "aabbccdd", k = 8
Output: 1
Explanation:
The only possible string is "aabbccdd".

Example 3:
Input: word = "aaabbb", k = 3
Output: 8

 

Constraints:
1 <= word.length <= 5 * 105
word consists only of lowercase English letters.
1 <= k <= 2000
*/

class Solution {
    const int mod = 1e9+7;
     int possibleStringCountAll(string s) {
        int n = s.size();
        long i = 0, ans = 1;
        while (i < n) {
            int j = i;
            while (j<n && s[i] == s[j]) {
                ++j;
            }
            ans *= j - i;
            ans %= mod;
            i = j;
        }
        return ans;
        
    }
public:


    int possibleStringCount(string s, int k) {
        /*
            aaabbb
            aabbb
            abbb
            aaabb
            aaab
            aabb
            abb
            aab
        */
        vector<int>dp(k+1, 0), dp2(k+1, 0);
        const int mod = 1e9+7;
        int n = s.size();
        int i = 0, min_length = 0;
        
        dp[0] = 1;

        {
            string tmp = s;
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            min_length = tmp.size();
        }
        

        // Optimization (2)
        if (min_length < k) {
            while (i<n) {
                int j = i;
                while (j<n && s[i] == s[j]) {
                    ++j;
                }
                int cnt = j - i;
                min_length += 1;
                i = j;
                
                for (int j=k-2; j>=0; --j) {

                    // Optimization (1)
                    // We have optimized this part
                    // See the fist submission
                    /*for (int c=1; c <=cnt && c + j < k; ++c) {
                        dp2[j+c] += dp[j];
                        if (dp2[j+c] >= mod) {
                            dp2[j+c] -= mod;
                        }
                    }*/
                    int l = j+1;
                    int r = min(j+cnt+1, k);

                    dp2[l] += dp[j];
                    dp2[r] += (mod - dp[j]);

                    if (dp2[l] >= mod) {
                        dp2[l] -= mod;
                    }
                    if (dp2[r] >= mod) {
                        dp2[r] -= mod;
                    }
                }
                for (int i=1; i<k; ++i) {
                    dp2[i] += dp2[i-1];
                    if (dp2[i] >= mod) {
                        dp2[i] -= mod;
                    }

                }
                for (int i=0; i<k; ++i) {
                    dp[i] = dp2[i];
                    dp2[i] = 0;
                }
                
            }
        }
        
        int all_size = possibleStringCountAll(s);
        int less_than_k_size = 0;
        for (int i=1; i<k; ++i) {
            less_than_k_size += dp[i];
            if (less_than_k_size >= mod) {
                less_than_k_size -= mod;
            }
        }
        
        //cout << all_size <<" "<< less_than_k_size << endl;
        
        int ans = (1ll * all_size - less_than_k_size + 2*mod) % mod;
        return ans;

    }
};
