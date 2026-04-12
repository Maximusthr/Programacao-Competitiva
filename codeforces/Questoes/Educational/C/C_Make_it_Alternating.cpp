#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;
const int MAX = 2e5+5;

vector<ll> fat;

void solve(){
    string s; cin >> s;

    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n-1; i++){
        if (s[i] == s[i+1]) ans++;
    }
    
    vector<ll> blocos;
    for (int i = 0; i < n-1; i++){
        int v = 0;
        while(i < n-1 && s[i] == s[i+1]){
            v++;
            i++;
        }
        if (v > 0) {
            blocos.push_back(v+1);
            v = 0;
        }
    }

    ll qtd = 1;
    for (int i = 0; i < blocos.size(); i++){
        qtd = (qtd * blocos[i]) % MOD;
    }

    qtd = (qtd * fat[ans]) % MOD;

    cout << ans << " " << qtd << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    fat.resize(MAX);
    fat[0] = 1;
    fat[1] = 1;
    for (int i = 2; i < MAX; i++){
        fat[i] = (fat[i-1] * i) % MOD;
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}
