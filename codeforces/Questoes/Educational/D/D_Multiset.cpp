#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;

struct BIT {
    int n;
    vector<int> bit;

    BIT (int _n) : n(_n), bit(n+1) {}

    void update(int i, int v){
        for (; i <= n; i += i & -i){
            bit[i] += v;
        }
    }

    int sum(int i){
        int ret = 0;
        for (; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }
};

void solve(){
    int n, q; cin >> n >> q;

    BIT bit(MAX);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        bit.update(x, 1);
    }

    while(q--){
        int x; cin >> x;
        if (x < 0){
            int l = 1, r = MAX-1;
            while(l < r){
                int mid = l + (r-l)/2;
                if (bit.query(1, mid) >= -x) r = mid;
                else l = mid + 1;
            }
            bit.update(l, -1);
        }
        else bit.update(x, 1);
    }

    int ans = -1;
    for (int i = 1; i < MAX; i++){
        if (bit.query(i, i) > 0){
            cout << i << "\n";
            return;
        }
    }

    cout << 0 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}