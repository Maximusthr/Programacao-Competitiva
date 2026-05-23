#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<int> bit;

    BIT(int _n) : n(_n), bit(n+1) {};

    void update(int i, int v){
        for (; i <= n; i += i & -i){
            bit[i] += v;
        }
    }

    ll sum(int i){
        ll ret = 0;
        for (; i; i -= i & -i){
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

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> copy = arr;
    sort(copy.begin(), copy.end());

    copy.resize(unique(copy.begin(), copy.end()) - copy.begin());

    for (int i = 0; i < n; i++){
        arr[i] = lower_bound(copy.begin(), copy.end(), arr[i]) - copy.begin();
    }

    vector<int> prefix(n+1);
    vector<int> left(n+1);
    for (int i = 0; i < n; i++){
        left[arr[i]]++;
        prefix[i] = left[arr[i]];
    }
    
    BIT bit(n);
    for (int i = 0; i < n; i++){
        bit.update(prefix[i], 1);
    }

    ll ans = 0;
    vector<int> suffix(n+1);
    for (int i = n-1; i >= 0; i--){
        bit.update(prefix[i], -1);

        suffix[arr[i]]++;

        ans += bit.query(suffix[arr[i]] + 1, n);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}