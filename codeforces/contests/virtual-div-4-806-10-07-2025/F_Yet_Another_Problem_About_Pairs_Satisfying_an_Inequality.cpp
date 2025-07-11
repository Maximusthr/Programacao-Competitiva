#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++){
        if (arr[i] < i) prefix[i]++;
    }

    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1];
    }

    ll ans = 0;
    for (int i = n; i >= 1; i--){
        if (arr[i] == 0) continue;
        if (i > arr[i]){
            ans += prefix[arr[i]-1];
        }
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