#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> pos(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        pos[x] = i;
    }

    int l = n, r = 0;
    string ans;
    for (int i = 0; i < n; i++){
        l = min(l, pos[i]);
        r = max(r, pos[i]);

        if (r-l == i){
            ans += '1';
        }
        else ans += '0';
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