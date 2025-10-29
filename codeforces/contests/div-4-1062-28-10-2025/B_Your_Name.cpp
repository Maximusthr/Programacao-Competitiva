#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;

    map<char, int> mapa_a;
    for (int i = 0; i < n; i++){
        mapa_a[a[i]]++;
    }

    map<char, int> mapa_b;
    for (int i = 0; i < n; i++){
        mapa_b[b[i]]++;
    }

    bool ok = true;
    for (auto [x, y] : mapa_a){
        if (mapa_b[x] != y){
            ok = false;
        }
    }
    for (auto [x, y] : mapa_b){
        if (mapa_a[x] != y){
            ok = false;
        }
    }

    if (ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}