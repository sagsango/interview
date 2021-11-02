// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1/?company[]=Amazon&company[]=Amazon&page=21&query=company[]Amazonpage21company[]Amazon

/*
	 Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.
 */
class Solution{
	public:
		int maxSquare(int n, int m, vector<vector<int>> mat){
			// code here
			/*
				 0000000
				 0000000
				 0000011
				 0000111
				 0000111

				 0000000
				 0000000
				 0001111
				 0001111
				 0001111
			 */
			int ans = 0;
			vector<vector<int>>dp(n,vector<int>(m));
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					if( mat[i][j] == 0 ){
						continue;
					}
					int x = (i ? dp[i-1][j] : 0 );
					int y = (j ? dp[i][j-1] : 0 );
					int z = (i && j ? dp[i-1][j-1] : 0 );

					int k = min({x,y,z});
					dp[i][j] = k + 1;

					ans = max(ans, dp[i][j]);
				}
			}
			return ans;
		}
};
