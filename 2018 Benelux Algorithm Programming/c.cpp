#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first 
#define S second 
#define int long long 

const int mxn = 1e5 + 3;

int32_t main()
{
    int n;
    cin >> n;
    int a = cbrt(n);
    while(n % a)
    {
        a--;
    }
    n /= a;
    int b = sqrt(n);
    while(n % b)
    {
        b--;
    }
    int c = n / b;
    // cout << a << ' ' << b << ' ' << c << '\n';
    cout << 2 * a * b + 2 * b * c + 2 * c * a << '\n';
}
