#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define piii pair<pii, int>
#define pb push_back
#define pp pop_back
#define F first.first
#define S first.second
#define TH second
#define sari ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair

const int mxn = 2e5 + 4;
piii a[mxn];

int32_t main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) 
        {
            cin >> a[i].F >> a[i].S;
            a[i].TH = i + 1;
        }
        sort(a, a + n);
        a[n] = {{-1, -1}, -1};
        int p = 0;
        vector<int> v;
        while(p < n)
        {
            while(a[p].F == a[p + 1].F) p++;
            v.pb(a[p].TH);
            p++;
        }
        cout << v.size() << '\n';
        sort(v.begin(), v.end());
        for(auto x : v) cout << x << " ";
        cout << '\n';
    }
}
