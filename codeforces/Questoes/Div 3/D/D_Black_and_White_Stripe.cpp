#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;

    vector<int> prefix(n+1);
    for (int i = 1; i <= n; i++){
        if (s[i-1] == 'W') prefix[i]++;
        prefix[i] += prefix[i-1];
    }

    int ans = INF;
    for (int i = k; i <= n; i++){
        ans = min(ans, prefix[i] - prefix[i-k]);
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