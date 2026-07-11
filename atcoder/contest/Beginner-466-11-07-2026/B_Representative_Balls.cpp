#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        freq[x] = max(freq[x], y);
    }

    vector<int> ans(101, -1);
    for (auto [x, y] : freq){
        ans[x] = y;
    }

    for (int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}