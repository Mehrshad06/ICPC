#include <bits/stdc++.h>
using namespace std;


const double q = sqrt(3) / 2;

inline double toRadians(double d) {
    return d * acos(-1) / 180.0;
}

int mamad(double z, double fa, int v1, int v2, int v3, int v4) {
    double m1 = fa * sin(toRadians(z + 60));
    double m2 = fa * cos(toRadians(z + 30));
    double m3 = fa * sin(toRadians(z));

    int i1 = static_cast<int>(floor(m1 / q)) % 4;
    int i2 = static_cast<int>(floor(m2 / q)) % 2;
    int i3 = static_cast<int>(floor(m3 / q)) % 2;



    vector<vector<vector<int>>> moo(4, vector<vector<int>>(2, vector<int>(2)));


    //  0
    moo[0][0][0] = v1;
    moo[0][0][1] = v3;
    moo[0][1][0] = v4;
    moo[0][1][1] = v2;
    
    // 1
    moo[1][0][0] = v2;
    moo[1][1][0] = v3;
    moo[1][0][1] = v4;
    moo[1][1][1] = v1;
    
    // 2
    moo[2][1][1] = v2;
    moo[2][0][1] = v3;
    moo[2][1][0] = v4;
    moo[2][0][0] = v1;
    
    //3
    moo[3][1][1] = v1;
    moo[3][1][0] = v3;
    moo[3][0][0] = v2;
    moo[3][0][1] = v4;
    

    
    return moo[i1][i2][i3];
}

int main() {
    string j1;
    int z1, fa1;
    cin >> j1 >> z1 >> fa1;
    string j2;
    int z2, fa2;
    cin >> j2 >> z2 >> fa2;
    int r1, r2;
    

    if (j1 == "BC") {
        r1 = mamad(z1, fa1, 1, 2, 3, 4);
    }
    else if (j1 == "CD") {
        r1 = mamad(z1, fa1, 4, 2, 1, 3);
    }
    else {
        r1 = mamad(z1, fa1, 3, 2, 4, 1);
    }
    
    if (j2 == "BC") {
        r2 = mamad(z2, fa2, 1, 2, 3, 4);
    }
    else if (j2 == "CD") {
        r2 = mamad(z2, fa2, 4, 2, 1, 3);
    }
    else {
        r2 = mamad(z2, fa2, 3, 2, 4, 1);
    }
    cout << (r1 == r2 ? "YES" : "NO") << endl;
    
    
    return 0;
}
