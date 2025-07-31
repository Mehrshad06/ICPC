#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define piii pair<pii, int>
#define F first
#define S second
#define int long long
#define pb push_back 

const int mxn = 1e4 + 1 , INF = 1e9, N = 31, K = 51;
int dp[33][33][53];
piii par[33][33][53];

int32_t main()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			for(int k = 0; k < K; k++) 
			{
				// if(i == 30 && j == 29 && k == 40) cout << "$$";
				dp[i][j][k] = INF;
				// if(i == 30 && j == 29 && k == 40) cout << dp[i][j][k] << " ";
			}
		for(int j = 0; j < N; j++) 
		{
			dp[i][j][0] = 0;
		}
	}
	// cout << dp[30][29][40] << '\n';
	// freopen("amme.txt", "w", stdout);
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < N; j++)
		{
			for(int k = 1; k <= min(K, i * j); k++)
			{
				if(k == i * j) dp[i][j][k] = 0;
				// bool qq = 0;
				// if(i == 30 && j == 29 && k == 40) qq = 1;
				// else qq = 0;
				// if(qq) cout << dp[i][j][k] << '\n';
				for(int kp = 0; kp <= k; kp++)
				{
					// if(qq) cout << "\n*" << kp << "*";
					for(int c = 1; c < i; c++)
					{
						// if(qq) cout << "\n(" << c << "):" << dp[c][j][kp] << ',' << dp[i - c][j][k - kp] << ',' << j << "^2";
						if(dp[c][j][kp] + dp[i - c][j][k - kp] + j * j < dp[i][j][k])
						{
							par[i][j][k] = {{c, j}, kp};
						}
						dp[i][j][k] = min(dp[i][j][k], dp[c][j][kp] + dp[i - c][j][k - kp] + j * j);	
					}
					for(int c = 1; c < j; c++)
					{
						// if(qq) cout << "\n(" << c << "):" << dp[i][c][kp] << ',' << dp[i][j - c][k - kp] << ',' << i << "^2";
						if(dp[i][c][kp] + dp[i][j - c][k - kp] + i * i < dp[i][j][k])
						{
							par[i][j][k] = {{i, c}, kp};
						}
						dp[i][j][k] = min(dp[i][j][k], dp[i][c][kp] + dp[i][j - c][k - kp] + i * i);
					}
				}
			}
		}
	}
	// for(int i = 1; i < N; i++)
	// {
	// 	for(int j = 1; j < N; j++)
	// 	{
	// 		for(int k = 1; k <= i * j && k < K; k++)
	// 		{
	// 			cout << "(" << i << ',' << j << ',' << k << "):" << dp[i][j][k];
	// 			cout << " from (" << par[i][j][k].F.F << "," << par[i][j][k].F.S << " | " << par[i][j][k].S << ")\n";
	// 		}		
	// 	}
	// }
	int T;
	cin >> T;
	while(T--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		cout << dp[n][m][k] << '\n';
	}
}
