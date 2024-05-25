// Longest Repeating Subsequence
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1/?company[]=Amazon&company[]=Amazon&page=15&query=company[]Amazonpage15company[]Amazon

/*
	 Given a string str, find the length of the longest repeating subsequence 
	 such that it can be found twice in the given string. The two identified 
	 subsequences A and B can use the same ith character from string str if and 
	 only if that ith character has different indices in A and B.
 */


class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		    int dp[n+1][n+1];
		    memset(dp,0,sizeof(dp));

		    for(int i=0;i<=n;++i){
		        for(int j=0;j<=n;++j){
		            if( i < n && j < n && i != j && str[i] == str[j] ){
		                dp[i+1][j+1] = max( dp[i+1][j+1], dp[i][j] + 1);
		            }
		            if( i < n ) dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
		            if( j < n ) dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
		        }
		    }
		    return dp[n][n];
		}

};

