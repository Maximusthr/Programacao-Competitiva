#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<int> bit;

    BIT (int _n) : n(_n), bit(n+1) {}

    BIT (vector<int> &v) : n(v.size()), bit(n+1){
        for (int i = 1; i <= n; i++){
            bit[i] += v[i-1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    int sum(int i){
        int ret = 0;
        for (i++; i; i -= (i & -i)){
            ret += bit[i];
        }
        return ret;
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }

    void update(int i, int v){
        for (i++; i <= n; i += (i & -i)){
            bit[i] += v;
        }
    }
};

int c = 1;
void solve(){
    cout << "Case " << c << ":\n";

    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    BIT bit(arr);

    while(q--){
        int x; cin >> x;
        if (x == 1){
            int idx; cin >> idx;
            bit.update(idx, -arr[idx]);
            cout << arr[idx] << "\n";
            arr[idx] = 0;
        }
        else if(x == 2){
            int idx, v; cin >> idx >> v;
            bit.update(idx, v);
            arr[idx] += v; 
        }
        else {
            int l, r; cin >> l >> r;
            cout << bit.query(l, r) << "\n";
        }
    }
    c++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}