#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first 
#define S second 
#define int long long 

const int mxn = 1e5 + 3;
int a[mxn];


int32_t main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 1;
    for(int i = 1; i < n;i++)
    {
        if(a[i] + a[i - 1] <= x) ans ++;
    }
    cout << ans << '\n';
    return 0;
}
