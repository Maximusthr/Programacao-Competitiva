#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;
const int TODO = 1e6+5;

int modPow(int a, int b){
    int x = 1;
    while(b > 0){
        if (b%2) x = 1ll * x * a % MOD;
        b >>= 1;
        a = 1ll * a * a % MOD;
    }

    return x;
}

void solve(){
    int n; cin >> n;
    
    vector<int> total(TODO);
    map<int, int> qtd;
    map<pair<int, int>, int> local;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int v; cin >> v;
            local[{i, v}] += 1;
            qtd[i] += 1;
        }
    }
    
    for (auto [x, y] : local){
        total[x.second] += 1;
    }
    
    int ans = 0;
    for (auto [x, y] : local){
        int invn = modPow(n, MOD-2);
        int invq = modPow(qtd[x.first], MOD-2);

        int a = (1 * invn) % MOD;
        int b = (1ll * y % MOD * invq % MOD) % MOD;
        int c = (1ll * total[x.second] % MOD * invn % MOD);

        int term = (int)(1ll * a % MOD * b % MOD) % MOD;
        term = (int)(1ll * term % MOD * c % MOD) % MOD;

        ans = (ans % MOD + term % MOD) % MOD;

    }

    cout << (int)(ans) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}