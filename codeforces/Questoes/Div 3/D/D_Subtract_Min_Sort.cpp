#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < n-1; i++){
        int v = min(arr[i], arr[i+1]);
        arr[i] = max(0, arr[i]-v);
        arr[i+1] = max(0, arr[i+1]-v);
    }
    
    if (is_sorted(arr.begin(), arr.end())){
        cout << "YES" << "\n";
        return;
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}