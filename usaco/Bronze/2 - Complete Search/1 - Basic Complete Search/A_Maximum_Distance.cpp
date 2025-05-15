#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int p; cin >> p;

    vector<int> x;
    vector<int> y;

    for (int i = 0; i < p; i++){
        int cx; cin >> cx;
        x.push_back(cx);
    }
    for (int i = 0; i < p; i++){
        int cy; cin >> cy;
        y.push_back(cy);
    }

    int ans = 0;
    for (int i = 0; i < p; i++){
        for (int j = 0; j < p; j++){
            if (i == j) continue;
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
 
            int dist = dx*dx + dy*dy;

            ans = max(ans, dist);
        }
    }

    cout << ans << "\n";
}
