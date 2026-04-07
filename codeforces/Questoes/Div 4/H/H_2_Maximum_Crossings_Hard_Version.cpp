#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<int> bit;

    BIT(int _n) : n(_n), bit(n+1){}

    BIT(vector<int> &v) : n(v.size()), bit(n+1){
        for (int i = 1; i <= n; i++){
            bit[i] += v[i-1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    };

    int sum(int i){
        int ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }

    void update(int i, int v){
        for (i++; i <= n; i += i & -i){
            bit[i] += v;
        }
    }
};  

void solve(){
    int n; cin >> n;

    BIT bit(n);
    ll ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        ans += bit.query(x, n-1);

        bit.update(x, 1);
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