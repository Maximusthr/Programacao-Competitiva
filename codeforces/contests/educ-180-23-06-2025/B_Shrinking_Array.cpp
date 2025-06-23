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
        if (abs(arr[i] - arr[i+1]) <= 1) {
            cout << 0 << "\n";
            return;
        }
    }
    if (n == 2){
        cout << -1 << "\n";
        return;
    }

    if ((is_sorted(arr.begin(), arr.end())) || (is_sorted(arr.begin(), arr.end(), greater<int>()))){
        cout << -1 << "\n";
    }
    else cout << 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}