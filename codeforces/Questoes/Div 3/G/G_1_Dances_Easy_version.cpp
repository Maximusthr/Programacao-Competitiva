#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> c(n);
    c[0] = 1;

    for (int i = 1; i < n; i++){
        cin >> c[i];
    }

    vector<int> b(n);
    for (auto &i : b) cin >> i;

    sort(c.begin(), c.end());
    sort(b.begin(), b.end(), greater<int> ());
    
    int ans = 0;
    int l = 0, r = n-1, fim = r;

    while(l <= r){
        while(fim >= 0 && r >= 0 && b[l] <= c[fim]){
            ans++;
            fim--;
            r--;
        }
        l++;
        fim--;
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