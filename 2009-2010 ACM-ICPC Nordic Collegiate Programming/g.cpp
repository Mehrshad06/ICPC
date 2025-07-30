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

const int mxn = 2600;
vector<int> adj[mxn];
bool mark[mxn];
int x1[mxn],x2[mxn], ans[mxn];
pii st[mxn], amme[mxn];
int par[mxn];
int dis[mxn];
vector<int> gh;
pii de;

void dfs(int v)
{
	mark[v] = 1;
	x1[v] = x2[v] = 0;
	amme[v] = {v, v};
	st[v] = {v, v};
	ans[v] = 0;
	for(auto x : adj[v])
	{
		if(!mark[x]) 
		{
			dfs(x);
			if(x1[v] < x1[x] + 1)
			{
				x2[v] = x1[v];
				x1[v] = x1[x] + 1;
				amme[v].S = amme[v].F;
				amme[v].F = amme[x].F;
			}
			else 
				if(x2[v] < x1[x] + 1)
				{
					x2[v] = x1[x] + 1;
					amme[v].S = amme[x].F;
				}
			if(ans[v] < ans[x])
			{
				ans[v] = ans[x];
				st[v] = st[x];
			}
		}
	}
	if(ans[v] < x1[v] + x2[v])
	{
		ans[v] = x1[v] + x2[v];
		st[v] = amme[v];
	}
}

void dfsr(int v)
{
	mark[v] = 1;
	for(auto x : adj[v])
	{
		if(!mark[x]) 
		{
			par[x] = v;
			dfsr(x);
		}
	}
}


void adfs(int v)
{
	mark[v] = 1;
	x1[v] = x2[v] = 0;
	amme[v] = {v, v};
	st[v] = {v, v};
	ans[v] = 0;
	for(auto x : adj[v])
	{		
		if(mp(v, x) == de) continue;
		if(mp(x, v) == de) continue;
		if(!mark[x]) 
		{
			par[x] = v;
			dis[x] = dis[v] + 1;
			adfs(x);
			if(x1[v] < x1[x] + 1)
			{
				x2[v] = x1[v];
				x1[v] = x1[x] + 1;
				amme[v].S = amme[v].F;
				amme[v].F = amme[x].F;
			}
			else 
				if(x2[v] < x1[x] + 1)
				{
					x2[v] = x1[x] + 1;
					amme[v].S = amme[x].F;
				}
			if(ans[v] < ans[x])
			{
				ans[v] = ans[x];
				st[v] = st[x];
			}
		}
	}
	if(ans[v] < x1[v] + x2[v])
	{
		ans[v] = x1[v] + x2[v];
		st[v] = amme[v];
	}
}

int findmid(pii a,int sz)
{
	int u = a.F;
	int v = a.S;
	if(dis[v] < dis[u])
	{
		swap(v, u);
	}
	// cout << "FFFFFF   " << u << ',' << v;
	int t = 0;
	while(t < sz / 2)
	{
		v = par[v];
		t++;
	}
	return v;
}


int32_t main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0);
	int root = st[0].F;
	int tah = st[0].S;
	// for(int i = 0; i < n; i++)
	// {
	// 	cout << i << ":" << ans[i] << ", " << x1[i] << ":" << amme[i].F << " | " << x2[i] << ":" << amme[i].S << "{" << st[i].F << "," << st[i].S << "}\n";
	// }
	fill(mark, mark + n, 0);
	dfsr(root);
	gh.pb(tah);
	while(gh.size() <= ans[0])
	{
		gh.pb(par[gh.back()]);
	}
	// for(auto i : gh) cout << i + 1 << " ";/////////////////////////////////////////
	// cout << '\n';////////////////////////////////////////////////////////////////
	int ANS = n + 2;
	pii e1, e2;
	e1 = e2 = {0, 0};
	for(int i = 1; i < gh.size(); i++)
	{
		de = {gh[i - 1], gh[i]};
		fill(mark, mark + n, 0);
		fill(x1, x1 + n, 0);
		fill(x2, x2 + n, 0);
		fill(par, par + n, 0);
		fill(dis, dis + n, 0);
		adfs(gh[i - 1]);
		adfs(gh[i]);
		int a = ans[gh[i - 1]];
		int b = ans[gh[i]];
		// cout << "de{" << de.F + 1 << "," << de.S  + 1 << "}{" << a << ',' << b << "}(" << (a + 1) / 2 + (b + 1) / 2 + 1 << ")";
		if(ANS > max((a + 1) / 2 + (b + 1) / 2 + 1, max(a, b)))
		{
			// cout << "!!!";
			ANS = max((a + 1) / 2 + (b + 1) / 2 + 1, max(a, b));
			int u = findmid(st[gh[i]], b);
			int v = findmid(st[gh[i - 1]], a);
			// cout << "{" << u << ',' << v << "}";
			e1 = mp(u, v);
			e2 = mp(gh[i], gh[i - 1]);
		}
		// cout << "\n";
	}
	cout << ANS << "\n";
	cout << e2.F + 1 << " " << e2.S + 1 << '\n';
	cout << e1.F + 1 << " " << e1.S + 1 << '\n';
	return 0;
}

/*
10
1 2
2 3
3 4
2 5
5 6
6 7
1 8
8 9
8 10
*/
