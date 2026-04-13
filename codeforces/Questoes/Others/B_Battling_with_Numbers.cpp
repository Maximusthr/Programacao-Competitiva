#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

ll binpow(ll a, ll b){
    ll x = 1;
    while (b > 0){
        if (b & 1) x = x * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return x;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n); 
    map<int, int> a_m, fa;
    for (auto &i : a){
        cin >> i;
        a_m[i]++;
    }
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        fa[a[i]] = x;
    }

    int m; cin >> m;
    vector<int> b(m);
    map<int, int> b_m, fb;
    for (auto &i : b){
        cin >> i;
        b_m[i]++;
    }
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        fb[b[i]] = x;
    }

    for (auto [x, y] : b_m){
        if (!a_m.count(x)){
            cout << 0 << "\n";
            return;
        }
    }
    for (auto [x, y] : fa){
        if (fb.count(x)){
            if (fb[x] > fa[x]){
                cout << 0 << "\n";
                return;
            }
        }
    }

    ll v = 0;
    for (auto [x, y] : a_m){
        if (!b_m.count(x) || fa[x] != fb[x]){
            v++;
        }
    }

    cout << binpow(2, v) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    solve();
}