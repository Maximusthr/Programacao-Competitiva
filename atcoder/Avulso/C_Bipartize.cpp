#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    
    
    vector<pair<int, int>> grafo;
    
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        grafo.push_back({x, y});
    }

    int ans = INF;
    for (int i = 0; i < (1 << n); i++){
        int aux = 0;

        for (int bit = 0; bit < m; bit++){
            auto [u, v] = grafo[bit];
            if ((1 & (i >> u)) == (1 & (i >> v))){
                aux++;
            }
        }

        ans = min(ans, aux);
    }

    cout << ans << "\n";
}
