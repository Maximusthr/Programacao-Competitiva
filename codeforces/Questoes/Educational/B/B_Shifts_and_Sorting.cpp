#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    s = '#' + s;

    int n = s.size();

    ll ans = 0;
    int cont = 0;
    int tot = 0;
    for (int i = 1; i < n; i++){
        if (s[i] == '1') tot++;
        else {
            if (tot > 0) {
                ans += i - cont;
                cont++;
            }
            else cont++;
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