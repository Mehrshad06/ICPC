#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
struct Shipment {
    ll a, b, c, d;
};

ll mamad(const vector<Shipment>& dd) {
    ll q = 0;
    for (const auto& s : dd) {
        if (s.a > s.c) {
            q += s.a - s.c;
        }
        ll miniii = min(s.a, s.c);
        if (s.b > s.d) {
            q += miniii + (s.b - s.d);
        }
    }
    return q;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ww;
    cin >> ww;
    
    while (ww--) {
        int n;
        cin >> n;
        
        vector<Shipment> dd(n);
        for (int i = 0; i < n; ++i) {
            cin >> dd[i].a >> dd[i].b >> dd[i].c >> dd[i].d;
        }
        cout << mamad(dd) << '\n';
    }
    return 0;
}
