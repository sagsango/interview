// https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1/?company[]=Amazon&company[]=Amazon&page=27&query=company[]Amazonpage27company[]Amazon
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

/*
	 Given a string s. In one step you can insert any character at any index of the string.
	 Return the minimum number of steps to make s palindrome.
	 A Palindrome String is one that reads the same backward as well as forward.
 */


class Solution {
public:
    int minInsertions(string a) {
        int n = a.length();
        string b = a;
        reverse(b.begin(),b.end());
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                if( i < n && j < n && a[i] == b[j] ){
                    dp[i+1][j+1] = max( dp[i+1][j+1], dp[i][j] + 1);
                }
                if( i < n )
                    dp[i+1][j] = max( dp[i+1][j], dp[i][j]);
                if( j < n )
                    dp[i][j+1] = max( dp[i][j+1], dp[i][j]);
            }
        }
        return n - dp[n][n];

    }
};
