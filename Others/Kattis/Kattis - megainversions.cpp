#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

struct BIT {
    int n;
    vector<ll> bit;

    BIT(int _n) : n(MAX), bit(MAX) {};

    void update(int i){
        for (i++; i < MAX; i += i & -i){
            bit[i]++;
        }
    }

    int sum(int i){
        int ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }

    int query(int l, int r){
        if (l > r) return 0;
        return sum(r) - sum(l-1);
    }
};

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    
    ll ans = 0;
    BIT bit1(n), bit2(n);

    vector<ll> left(n+1), right(n+1);
    for (int i = 0; i < n; i++){
        left[i] = bit1.query(arr[i], MAX-1);
        bit1.update(arr[i]-1);
    }

    for (int i = n-1; i >= 0; i--){
        right[i] = bit2.query(0, arr[i] - 2);
        bit2.update(arr[i]-1);
    }

    for (int i = 0; i < n; i++){
        ans += left[i] * right[i];
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}