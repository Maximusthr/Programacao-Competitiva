#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    string s; cin >> s;

    map<char, int> val;

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (val[s[i]] == 0) ans += 2;
        else ans++;
        val[s[i]]++;
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