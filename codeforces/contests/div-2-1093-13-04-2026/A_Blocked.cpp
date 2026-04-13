#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    sort(arr.begin(), arr.end(), greater<int>());

    for (int i = 1; i < n; i++){
        if (arr[i] == arr[i-1]){
            cout << "-1" << "\n";
            return;
        }
    }

    for (auto &i : arr) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}