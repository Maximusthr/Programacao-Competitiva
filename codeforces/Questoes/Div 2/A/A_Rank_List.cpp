#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    
    struct tipo{
        bool operator()(const pair<int, int> &p, const pair<int, int> &pp) const{
            if (p.first != pp.first) return p.first > pp.first;
            return p.second < pp.second;
        };
    };

    map<pair<int, int>, int, tipo> mapa;
    for (int i = 0; i < n; i++){
        int x, t; cin >> x >> t;
        mapa[{x, t}]++;
    }

    vector<int> qtd(51);
    for (int i = 0; i < n; i++){
        for (auto [x, y] : mapa){
            for (int j = 0; j < y; j++){
                qtd[i++] += y;
            }
        }
    }

    cout << qtd[k-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}