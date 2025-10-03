#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+5;

void solve(){
    int n; cin >> n;

    ll ans = 0;
    map<int, ll> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        ans += arr[x-i];

        arr[x-i] += 1;
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