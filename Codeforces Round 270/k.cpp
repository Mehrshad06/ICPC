#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string of, soton;
    cin >> of >> soton;
    
    int size = n * m;
    vector<vector<bool>> okbo(size, vector<bool>(size, false));


    for (int i = 0; i < size; i++) {
        okbo[i][i] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = i * m + j;
            if (of[i] == '<') {
                if (j > 0) {
                    int v = i * m + (j - 1);
                    okbo[u][v] = true;
                }
            } else {
                if (j < m - 1) {
                    int v = i * m + (j + 1);
                    okbo[u][v] = true;
                }
            }
            if (soton[j] == '^') {
                if (i > 0) {
                    int v = (i - 1) * m + j;
                    okbo[u][v] = true;
                }
            } else {
                if (i < n - 1) {
                    int v = (i + 1) * m + j;
                    okbo[u][v] = true;
                }
            }
        }
    }
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (okbo[i][k] && okbo[k][j]) {
                    okbo[i][j] = true;
                }
            }
        }
    }
    bool alll = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (!okbo[i][j]) {
                alll = false;
                break;
            }
        }
        if (!alll) break;
    }
    cout << (alll ? "YES" : "NO") << endl;
    return 0;
}
