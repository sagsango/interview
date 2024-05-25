

dp[ lenght ][ last used index of other ][ last used ]


fill dp with +inf.

dp[0][0][0] = dp[0][0][1] = 0;

for(int i=0;i<L;++i){
	for(int j=0;j<=L;++j){
		for(int k=0;k<2;++k){
			dp[i+1][j][k] = min( dp[i+1][j][k], dp[i][j][k] + cost[i][i+1][k] );
			dp[i+1][i][k^1] = min( dp[i+1][i][k^1], dp[i][j][k] + cost[j][i+1][k^1] );
		}
	}
}


dp[ node ][ count of security type = k ][ security type less that k, equal to k, greater than k ]
void dfs(int u,int p){
	dp[u][0][0] = k-1;
	dp[u][1][1] = 1;
	dp[u][0][2] = m-k;
	for(auto v:g[u]){
		if( v != p ){
			for(int i=0;i<=K;++i){
				for(int j=0;j<=K;++j){
					if( i + j <= K ){
						tmp[u][i+j][0] = add( tmp[u][i+j][0], mul(dp[u][i][0], add(dp[v][j][0],add(dp[v][j][1],dp[v][j][2]))) );
						tmp[u][i+j][1] = add( tmp[u][i+j][1], mul(dp[u][i][1], dp[v][j][0]) );
						tmp[u][i+j][2] = add( tmp[u][i+j][2], mul(dp[u][i][2], add(dp[v][j][0],dp[v][j][2]) );
					}
				}
			}
		}
	}
}


