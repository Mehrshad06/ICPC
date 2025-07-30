#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define sari ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int mxn = 1e5 + 3;
int a[mxn];
vector<int> adj[mxn];
int par[mxn];
pii e[mxn];
int t[mxn];
int ans[mxn];

int root(int v)
{
	if(par[v] == v) return v;
	return par[v] = root(par[v]);
	// return (par[v] == v) ? v : par[v] = root(par[v]);
}

int32_t main()
{
	sari
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		e[i] = {u, v};
	}
	for(int i = 0; i < n; i++)
	{
		par[i] = i;
		t[i] = 1;
	}
	for(int i = 0; i < m; i++)
	{
		int u, v;
		u = e[i].F;
		v = e[i].S;
		// cout << "{" << u << "," << v << "}=>";
		u = root(u);
		v = root(v);
		// cout << "{" << u << "," << v << "}=>";
		if(t[u] > t[v])
		{
			swap(u, v);
		}
		// cout << "{" << u << "," << v << "}=>";
		if(u != v)
		{
			// cout << u << "became" << v;
			t[v] += t[u];
			par[u] = v;
		}
		// cout << '\n';
	}
	// cout << "p:";//////////////////////////////////////////////////////////////
	for(int i = 0; i < n; i++)
	{
		int p = root(i);
		ans[p] += a[i];
		// cout << "{" << i << ":" << p << "} ";////////////////////////////////////////////
	}
	// cout << '\n';//////////////////////////////////////////////
	for(int i = 0; i < n; i++)
	{
		if(ans[i])
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	cout << "POSSIBLE\n";
	return 0;
}
