#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    vector<ll> prefix(n+2), suffix(n+2);

    prefix[1] = 1;
    prefix[n] = 1;

    for (int i = 1; i < n-1; i++){
        // i com i - 1
        // i com i + 1

        if (arr[i+1] - arr[i] < arr[i] - arr[i-1]) prefix[i+1] = 1;
        else prefix[i+1] = arr[i+1] - arr[i];
    }

    suffix[1] = 1;
    suffix[n] = 1;

    for (int i = n-2; i >= 1; i--){
        // i com i + 1
        // i com i - 1

        if (arr[i] - arr[i-1] < arr[i+1] - arr[i]) suffix[i+1] = 1;
        else suffix[i+1] = arr[i] - arr[i-1];
    }

    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1];
    }
    for (int i = n; i >= 1; i--){
        suffix[i] += suffix[i+1];
    }


    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;

        if (x < y){
            // prefixo
            cout << prefix[y-1]  - prefix[x-1] << "\n";
        }
        else {
            // sufixo
            cout << suffix[y+1] - suffix[x+1] << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}