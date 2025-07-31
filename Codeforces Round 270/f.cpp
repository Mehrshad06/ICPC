#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define piii pair<pii, int>
#define F first
#define S second
#define int long long
#define pb push_back 

const int mxn = 2e5 + 5 , INF = 1e9;
pair<string, int> a[mxn];
int p[mxn];

int32_t main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		a[2 * i] = {s, i + 1};
		cin >> s;
		a[2 * i + 1] = {s, i + 1};
	}
	for(int i = 0; i < n; i++) cin >> p[i];
	sort(a, a + 2 * n);
	// for(int i = 0; i < 2 * n; i++) cout << a[i].F << " " << a[i].S << '\n';
	int pt = 0;
	for(int i = 0; i < 2 * n; i++)
	{
		if(a[i].S == p[pt]) pt++;
		if(pt == n)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
