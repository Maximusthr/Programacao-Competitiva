#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    ll sep[n+1], join[n+1];

    memset(sep, 0, sizeof(sep));
    memset(join, 0, sizeof(join));
 
    sep[0] = join[0] = 1;

    for (int i = 1; i < n; i++){
        join[i] = 2 * join[i-1] + sep[i-1];
        join[i] %= MOD;

        sep[i] = 4 * sep[i-1] + join[i-1];
        sep[i] %= MOD;
    }

    cout << (sep[n-1] + join[n-1]) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}