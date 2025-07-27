#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, c; cin >> n >> c;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

   
    set<int> idx;
    sort(arr.begin(), arr.end());
    vector<ll> copy = arr;
    
    while (true){
        ll dif = -1;
        for (int i = 0; i < n; i++){
            if (copy[i] <= c && !idx.count(i)){
                dif = i;
            }
        }
        
        if (dif == -1) break;
        
        idx.insert(dif);
        for (int i = 0; i < n; i++){
            if (idx.count(i)) continue;
            copy[i] *= 2;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (copy[i] > c) ans++;
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