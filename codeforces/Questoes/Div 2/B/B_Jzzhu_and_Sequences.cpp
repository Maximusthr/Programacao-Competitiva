#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

void solve(){
    ll x, y; cin >> x >> y;
    
    ll n; cin >> n;

    array<ll, 11> arr;

    arr[1] = x;
    arr[2] = y;

    for (int i = 3; i <= 10; i++){
        arr[i] = arr[i-1] - arr[i-2];
    }

    int v = (n % 6 == 0 ? 6 : n % 6);

    ll ans = arr[v];

    cout << (ans + 2*MOD) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}