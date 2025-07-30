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

const int mxn = 1e6 + 4, INF = 1e15, N = 1e6 + 2;
bool pr[mxn];

int32_t main()
{
	// freopen("stdin.txt", "r", stdin);
	// freopen("stdout.txt", "w", stdout);
	int n;
	cin >> n;
	for(int i = 2; i * i < N; i++)
	{
		if(!pr[i])
		{
			for(int j = i + i; j < N; j += i) pr[j] = 1;
		}
	}
	// for(int i = 0; i < n; i++) cout << "(" <<i << '=' << pr[i] << ")"; 
	int a = 4;
	while(a < n)
	{
		if(pr[a] && pr[n - a])
		{

			cout << a << " " << n - a << '\n';
			return 0;
		}
		a++;
	}
}
