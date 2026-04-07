#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve
void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }

    int m; cin >> m;
    m--;

    int flip = 0;
    int l = m, r = m;
    int ans = 0;
    while (l >= 0 || r < n){
        while(l >= 0 && arr[l] == arr[m]) l--;
        while(r < n && arr[r] == arr[m]) r++;

        if (l >= 0 || r < n){
            ans++;
            flip ^= 1;
            arr[m] ^= 1;
        }
    }

    if (flip){
        ans++;
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