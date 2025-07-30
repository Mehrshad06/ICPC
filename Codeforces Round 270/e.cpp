#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }



    unordered_map<int, ll> gg;
    unordered_map<int, ll> gt;


    for (int i = 0; i < n; i++) {
        unordered_map<int, ll> ng;
        ng[a[i]]++;

        for (auto [g, q] : gt) {
            int sng = __gcd(g, a[i]);
            ng[sng] += q;
        }
        for (auto [g, q] : ng) {
            gg[g] += q;
        }
        gt = move(ng);
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << gg[x] << '\n';
    }

    return 0;
}
