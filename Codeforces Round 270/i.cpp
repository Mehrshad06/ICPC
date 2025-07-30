#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sari ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int MAXN = 150000 + 10;
const int MAXM = 300 + 10;


ll dp[2][MAXN]; 
int a[MAXM], b[MAXM], t[MAXM];

int main() {
    sari
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i] >> t[i];
    }
    int makan = 0;
    for (int x = 1; x <= n; ++x) {
        dp[makan][x] = b[1] - abs(a[1] - x);
    }

    for (int i = 2; i <= m; ++i) {
        ll dt = t[i] - t[i - 1];
        ll mo = d * dt;
        deque<int> dq;
        int xp = makan ^ 1;
        for (int x = 1; x <= n; ++x) {
            while (!dq.empty() && dp[makan][dq.back()] <= dp[makan][x]) {
                dq.pop_back();
            }
            dq.push_back(x);
            while (!dq.empty() && dq.front() < x - mo) {
                dq.pop_front();
            }
            dp[xp][x] = dp[makan][dq.front()] + b[i] - abs(a[i] - x);
        }
        dq.clear();
        for (int x = n; x >= 1; --x) {
            while (!dq.empty() && dp[makan][dq.back()] <= dp[makan][x]) {
                dq.pop_back();
            }
            dq.push_back(x);
            while (!dq.empty() && dq.front() > x + mo) {
                dq.pop_front();
            }
            dp[xp][x] = max(dp[xp][x], dp[makan][dq.front()] + b[i] - abs(a[i] - x));
        }
        makan = xp;
    }


    
   ll ja = dp[makan][1]; 
for (int x = 2; x <= n; ++x) {
    if (dp[makan][x] > ja) {
        ja = dp[makan][x];
    }
}
cout << ja << endl;
return 0;

}
