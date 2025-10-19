#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;

    vector<int> pos;

    for (int i = 0; i < n; i++){
        if (s[i] == '1') pos.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < pos.size(); i++){
        if (i == 0) {
            ans++; continue;
        }
        if (pos[i] - pos[i-1] >= k) ans++;
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