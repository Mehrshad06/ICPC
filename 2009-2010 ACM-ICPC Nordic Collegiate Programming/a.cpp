#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define sari ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int32_t main()
{
	sari
	int e, f, c;
	cin >> e >> f >> c;
	int b = e + f;
	int ans = 0;
	while(b >= c)
	{
		int u = b / c;
		ans += u;
		b %= c;
		b += u;
	}
	cout << ans << '\n';
	return 0;
}
