#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int v = 0;
    for (int i = 0; i < n; i++){
        v = __gcd(v, arr[i]);
    }

    if (v == 1){
        cout << 0 << "\n";
        return;
    }

    v = INF;
    for (int i = 0; i < n; i++){
        if (__gcd(arr[i], i+1) == 1) v = min(v, n - (i+1) + 1);
    }

    int aux = INF;
    for (int i = n-1; i >= 0; i--){
        int v = __gcd(arr[i], i+1);
        
        for (int j = 0; j < n; j++){
            if (i == j) continue;

            v = __gcd(v, arr[j]);
            if (v == 1){
                aux = min(aux, n - (i+1) + 1);
            }
        }
    }

    cout << min({aux, v, 3}) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}