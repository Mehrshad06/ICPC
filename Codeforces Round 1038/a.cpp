#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        if (n == 1 || m == 1) {
            cout << "NO\n";
        } else if (n == 2 && m == 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
