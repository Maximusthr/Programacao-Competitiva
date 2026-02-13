#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s, t; cin >> s >> t;
    
    int S = s.size(), T = t.size();

    ll p = 53;
    ll MOD = 1e9 + 9;
    vector<ll> p_pow(max(S, T));

    p_pow[0] = 1;
    for (int i = 1; i < max(S, T); i++){
        p_pow[i] = (p_pow[i-1] * p) % MOD;
    }

    vector<ll> hash_s(S+1);
    for (int i = 0; i < S; i++){
        hash_s[i+1] = (hash_s[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    ll hash_t = 0;
    for (int i = 0; i < T; i++){
        hash_t = (hash_t + (t[i]-'a'+1) * p_pow[i]) % MOD;
    }

    int ans = 0;
    for (int i = 0; i + T - 1 < S; i++){
        ll comp_hash_s = (hash_s[i+T] - hash_s[i] + MOD) % MOD;
        ll comp_hash_t = hash_t * p_pow[i] % MOD;
        if (comp_hash_s == comp_hash_t){
            ans++;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}