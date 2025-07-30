#include <bits/stdc++.h>

using namespace std;

int main() {
int x, y, n;
cin >> x >> y >> n;


double q = static_cast<double>(x) / y;
int ma = 0, mb = 1;
double agh = INT_MAX;

for (int b = 1; b <= n; ++b) {
    int a = static_cast<int>(q * b);
    for (int i : {a, a + 1}) {
        double w = abs(q - static_cast<double>(i) / b);
        if (w < agh || (w == agh && b < mb) || (w == agh && b == mb && i < ma)) {
            agh = w;
            ma = i;
            mb = b;
        }
    }
}

cout << ma << "/" << mb << endl;
return 0;
}
