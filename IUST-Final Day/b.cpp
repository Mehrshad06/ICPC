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

const int mxn = 1e5 + 3, N = 3, M = 3, K = 5, INF = 1e17;
int a[mxn], mn = INF, ind;

int32_t main()
{
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = x; i < n; i++)
	{
		if(a[i] <= mn) 
		{
			mn = a[i];
			ind = i;
		}
		// cout << i << ":" << mn << "," << ind << " ";
	}
	for(int i = 0; i < x; i++)
	{
		if(a[i] <= mn) 
		{
			mn = a[i];
			ind = i;
		}
		// cout << i << ":" << mn << "," << ind << " ";
	}
	// cout << ind + 1 << "\n";
	if(x >= ind + 1)
	{
		a[ind] = x + n - (ind + 1) + n * (a[ind] - 1);
		for(int i = 0; i < n; i++)
		{
			if(i < ind) cout << a[i] - mn << " ";
			if(i == ind) cout << a[i] << " ";
			if(i > ind && i + 1 <= x) cout << a[i] - mn - 1 << " ";
			if(i + 1 > x) cout << a[i] - mn << " ";
		}
		cout << '\n';
		return 0;
	}
	else
	{
		a[ind] = n - (ind + 1) + x + n * a[ind];
		for(int i = 0; i < n; i++)
		{
			// cout << "(" << i << ")";
			if(i + 1 <= x) cout << a[i] - mn - 1 << " ";
			if(i + 1 > x && i < ind) cout << a[i] - mn << " ";
			if(i == ind) cout << a[i] << " ";
			if(i > ind) cout << a[i] - mn - 1 << " ";
		}
		cout << '\n';
		return 0;

	}
	return 0;
}
