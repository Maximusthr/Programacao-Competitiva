#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> f(n);
    for (auto &i : f) cin >> i;

    vector<ll> ans(n);
    for (int i = 1; i < n-1; i++){
        ans[i] = f[i+1] + f[i-1] - 2*f[i];
        ans[i] >>= 1;
    }

    ll v_0 = 0;
    for (int i = 1; i < n-1; i++){
        v_0 += (ans[i] * (n-i-1));
    }
    ans[0] = (f[n-1] - v_0)/(n-1);

    v_0 = 0;
    for (int i = 1; i < n-1; i++){
        v_0 += (ans[i] * (i));
    }
    ans[n-1] = (f[0] - v_0)/(n-1);

    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}