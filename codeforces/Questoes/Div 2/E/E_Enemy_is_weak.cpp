#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;

    BIT(T _n) : n(_n), bit(n+1) {}

    BIT(vector<T> v) : n(v.size()), bit(n+1){
        for (int i = 1; i <= n; i++){
            bit[i] += v[i-1];
            int j = i + i & -1;
            if (j <= n) bit[j] += bit[i];
        }
    };

    T sum(int i){
        T resp = 0;
        for (i++; i; i -= i & -i) resp += bit[i];
        return resp;
    }

    T query(int l, int r){
        return sum(r) - sum(l-1);
    }

    void update(int i, T v){
        for (i++; i <= n; i += i & -i) bit[i] += v;
    }
};

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> b = arr;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());

    for (int i = 0; i < n; i++){
        arr[i] = lower_bound(b.begin(), b.end(), arr[i]) - b.begin();
    }

    vector<int> left(n), right(n);

    BIT bit(n);
    for (int i = 0; i < n; i++){
        left[i] = bit.query(arr[i] + 1, n - 1);
        bit.update(arr[i], 1);
    }
    
    BIT bit2(n);
    for (int i = n-1; i >= 0; i--){
        right[i] = bit2.query(0, arr[i] - 1);
        bit2.update(arr[i], 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += 1ll * left[i] * right[i];
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}