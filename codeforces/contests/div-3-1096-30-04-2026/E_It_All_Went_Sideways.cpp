#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;

struct BIT {
    int n;
    vector<ll> bit;
    
    BIT (int _n) : n(_n), bit(n) {};

    void update(int i, int v){
        for (i++; i <= n; i += i & -i){
            bit[i] += v;
        }
    }

    ll sum(int i){
        ll ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }

        return ret;
    }

    ll query(int l, int r){
        return sum(r) - sum(l-1);
    }
};

BIT bit(MAX);

void solve(){
    int n; cin >> n;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    ll ans = 0;
    vector<ll> suffix(n+2, LINF);
    for (int i = n; i > 0; i--){
        ans += max(0ll, arr[i] - suffix[i+1]);
        suffix[i] = min(suffix[i+1], arr[i]);
    }

    ll ext = 0;
    vector<ll> aux;
    
    for (int i = 1; i <= n; i++){
        bit.update(arr[i], 1);
        aux.push_back(arr[i]);

        if (suffix[i] != suffix[i+1]){
            ext = max(ext, bit.query(arr[i], MAX-5) - 1);
            for (auto k : aux) bit.update(k, -1);
            aux.clear();
        }
    }

    cout << ans + ext  << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}