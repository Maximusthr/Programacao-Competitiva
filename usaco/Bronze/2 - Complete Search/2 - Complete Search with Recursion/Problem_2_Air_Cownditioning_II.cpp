// BITMASK

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct cow{
    int x, y, c;
};

struct air{
    int x, y, p, c;
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<cow> vacas;
    for (int i = 0; i < n; i++){
        int x, y, c; cin >> x >> y >> c;
        vacas.push_back({x, y, c});
    }
    
    vector<int> real(101);
    for (int i = 0; i < n; i++){
        for (int j = vacas[i].x; j <= vacas[i].y; j++){
            real[j] += vacas[i].c;
        }
    }

    vector<air> ar;
    for (int i = 0; i < m; i++){
        int x, y, p, c; cin >> x >> y >> p >> c;
        ar.push_back({x, y, p, c});
    }

    int custo = INF;

    for (int i = 0; i < (1 << m); i++){
        int sum = 0;
        vector<int> red(101);
        for (int bits = 0; bits < m; bits++){
            if (i & (1 << bits)){
                sum += ar[bits].c;
                for (int k = ar[bits].x; k <= ar[bits].y; k++){
                    red[k] += ar[bits].p;
                }
            }
        }
        bool ok = true;
        for (int j = 0; j < 101; j++){
            if (red[j] < real[j]) {
                ok = false;
                break;
            }
        }
        if (ok) custo = min(custo, sum);
    }

    cout << custo << "\n";
}