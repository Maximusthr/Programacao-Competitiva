#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll ans = LINF;
int primos(ll n){
    if (__gcd(1ll*n, 1ll*2) == 1){
        return 2;
    }
    for (int i = 3; i < 10000; i += 2){
        if (i >= ans) return ans;
        if (__gcd(1ll*n, 1ll*i) == 1){
            return i;
        }
    }
}

void solve(){
    int n; cin >> n;

    ans = LINF;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < n; i++){
        ans = min(ans, 1ll*primos(arr[i]));
    }

    if (ans == LINF){
        cout << -1 << "\n";
    }
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}