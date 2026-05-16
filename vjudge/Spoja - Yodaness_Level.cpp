#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<int> bit;

    BIT (int _n) : n(_n), bit(n+1) {}

    ll query(ll i){
        ll ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }

    void update(int i){
        for (i++; i <= n; i += i & -i){
            bit[i] += 1;
        }
    }
};

void solve(){
    int n; cin >> n;

    vector<string> a(n);
    for (auto &i : a) cin >> i; 

    vector<int> arr(n);
    map<string, int> mapa;

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        mapa[s] = i;
    }

    for (int i = 0; i < n; i++){
        arr[i] = mapa[a[i]];
    }

    ll ans = 0;
    BIT bit(n);
    for (int i = n-1; i >= 0; i--){
        ans += bit.query(arr[i]);

        bit.update(arr[i]);
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