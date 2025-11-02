#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<pair<int, int>> def(m);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        def[i] = {x, y};
    }
    
    sort(def.begin(), def.end());

    vector<ll> prefix(m+1);
    vector<int> f;
    for (int i = 0; i < m; i++){
        prefix[i+1] = prefix[i] + def[i].second;
        f.push_back(def[i].first);
    }

    for (int i = 0; i < n; i++){
        auto it = upper_bound(f.begin(), f.end(), arr[i]) - f.begin();

        cout << prefix[it] << " \n"[i==n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}