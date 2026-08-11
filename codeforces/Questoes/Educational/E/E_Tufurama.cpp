#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<int> bit;

    BIT(int _n) : n(_n), bit(n+2) {};

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

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    vector<vector<int>> lim(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i]--;
        arr[i] = min(arr[i], n);
        lim[min(i - 1, arr[i] + 1)].push_back(i-1);
    }

    BIT bit(n+2);
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        bit.update(arr[i], 1);
        for (auto y : lim[i]){
            ans += bit.query(y, n+1);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}