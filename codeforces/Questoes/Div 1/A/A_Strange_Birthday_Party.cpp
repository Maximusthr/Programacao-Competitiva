#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<pair<int, int>> a(n);
    vector<int> b(m);
    queue<int> fila;

    for (auto &i : a) cin >> i.first;

    for (int i = 0; i < m; i++){
        cin >> b[i];
        fila.push(b[i]);
    }

    for (int i = 0; i < n; i++){
        a[i].second = b[a[i].first - 1];
    }

    sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b){
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i].second > fila.front()){
            ans += fila.front();
            fila.pop();
        }
        else {
            ans += a[i].second;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}