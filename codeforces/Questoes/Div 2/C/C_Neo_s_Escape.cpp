#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int usei = 0;
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (pos.size() > 0 && pos.back().first == x) {
            usei++;
        }
        else pos.push_back({x, i-usei});
    }

    n = (int)pos.size();
    vector<bool> tudo(n);

    sort(pos.begin(), pos.end(), [&](pair<int, int> x, pair<int, int> y){
        if (x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    }); 

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (pos[i].second - 1 >= 0 && tudo[pos[i].second - 1]){
            tudo[pos[i].second] = true;
        }
        if (pos[i].second + 1 < n && tudo[pos[i].second + 1]){
            tudo[pos[i].second] = true;
        }
        if(!tudo[pos[i].second]) {
            ans++;
            tudo[pos[i].second] = true;
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