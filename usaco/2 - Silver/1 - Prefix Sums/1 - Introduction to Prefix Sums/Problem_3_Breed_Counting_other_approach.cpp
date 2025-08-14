#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    
    int n, q; cin >> n >> q;

    vector<int> H(n+1); // 1
    vector<int> G(n+1); // 2
    vector<int> J(n+1); // 3

    for (int i = 0; i < n; i++){
        H[i+1] = H[i];
        G[i+1] = G[i];
        J[i+1] = J[i];

        int k; cin >> k;
        if (k == 1) H[i+1]++;
        if (k == 2) G[i+1]++;
        if (k == 3) J[i+1]++;
    }

    while(q--){
        int x, y; cin >> x >> y;
        
        cout << H[y] - H[x-1] << " " << G[y] - G[x-1] << " " << J[y] - J[x-1] << "\n";
    }
}
