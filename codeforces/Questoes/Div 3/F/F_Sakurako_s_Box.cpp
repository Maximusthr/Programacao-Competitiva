#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

ll modPow(ll a, ll b){  
    ll x = 1;
    while(b > 0){
        if (b % 2) x = (x % MOD * a % MOD) % MOD;
        b >>= 1;
        a = ((a % MOD) * (a % MOD)) % MOD;
    }  

    return x;
}

void solve(){
    int n; cin >> n;

    vector<ll> arr(n+1);
    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }

    ll ans = 0;
    ll qtd = 0;
    for (int i = 1; i <= n; i++){
        ans += (((prefix[n]-prefix[i]) % MOD) * (arr[i] % MOD)) % MOD;
        ans %= MOD;
        qtd += n-i;
    }
    
    cout << (ans * modPow(qtd, MOD-2) % MOD) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}