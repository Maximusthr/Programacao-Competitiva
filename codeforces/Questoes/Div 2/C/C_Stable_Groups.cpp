#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k, x; cin >> n >> k >> x;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    vector<ll> dif;
    for (int i = 1; i < n; i++){
        dif.push_back(arr[i] - arr[i-1]);
    }

    sort(dif.begin(), dif.end());

    int ans = 0;
    bool flag = 0;
    for (int i = 0; i < dif.size(); i++){
        ll v = dif[i];
        if (v <= x) continue;

        ll al = v/x;
        if (v % x == 0) al--;

        if (al <= k) {
            k -= al;
            continue;
        }

        if (!flag){
            flag = true;
            ans += 2;
        }
        else ans++;
    }

    if (ans == 0) ans++;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}