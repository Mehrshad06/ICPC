#include <bits/stdc++.h>
using namespace std;
#define double long double 

void solve() {
    double l, k, t1,t2, h;
    cin >> l >> k >> t1 >>t2 >> h;

    if (h < l) {
        cout << fixed << setprecision(6) << h << " " << h << endl;
        return;
    } else if (h == l) {
        double f1 = l;
        double a = t1;
        double b = -(l + k * t1 + k *t2);
        double c = k * l;
        double del = b * b - 4 * a * c;
        double r = (-b + sqrt(del)) / (2 * a);
        double f2 = r * t1;
        cout << fixed << setprecision(6) << f1 << " " << f2 << endl;
    } else {
        double a = t1;
        double b = -(h + k * t1 + k *t2);
        double c = k * l;
        double del = b * b - 4 * a * c;
        double r = (-b + sqrt(del)) / (2 * a);
        double f2 = r * t1;

        cout << fixed << setprecision(6)        << f2 << " " << f2 << endl;
    }
}

int main() {
    solve();
    return 0;
}
