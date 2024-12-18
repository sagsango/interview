/*
1153. String Transforms Into Another String
Solved
Hard


Hint
Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.
In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.
Return true if and only if you can transform str1 into str2.

 
Example 1:
Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.

Example 2:
Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.
 

Constraints:

1 <= str1.length == str2.length <= 104
str1 and str2 contain only lowercase English letters.
*/



class Solution {
    vector <unordered_set<int>> g;
public:
    bool canConvert(string str1, string str2) {
        /*



        "aabcc",
        "ccdee"

        a -> c  (3,2)
        b -> d  (2, 3)
        c -> e  (1)



        "leetcode"
        "codeleet"
        l -> c
        e -> o
        e -> d
        t -> e
        c -> l
        o -> e
        d -> e
        e -> t


        outdegree should be 1
        str2 unique char < 26  or str1 == str2
        */


        if (str1 == str2) {
            return true;
        }

        g = vector <unordered_set<int>>(26);
        unordered_set<char> st2;
        int n = str1.size();
        for (int i=0; i<n; ++i) {
            int u = str1[i] - 'a';
            int v = str2[i] - 'a';
            g[u].insert(v);
            if (g[u].size() > 1) {
                return false;
            }
            st2.insert(v);
        }

        if (st2.size() == 26) {
            return false;
        }

        return true;

       
    }
};