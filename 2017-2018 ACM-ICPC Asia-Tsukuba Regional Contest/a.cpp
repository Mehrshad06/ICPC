#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define sari ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair
#define X first
#define Y second

const int mxn = 105;
int dp[mxn];


int32_t main()
{
	int n, k;
	cin >> n >> k;
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(i == k) dp[i] = 1;
		dp[i] += dp[i - 2];
		if(i - k - 1 >= 0) dp[i] += dp[i - k - 1];
	}
	int ans = 0;
	// for(int i = 0; i <= n; i++) cout << dp[i] << " ";
	// cout << '\n';
	for(int i = 1; i <= n; i++) ans += dp[i];
	cout << ans << '\n';
}
