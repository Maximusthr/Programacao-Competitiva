#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (n == 1) {
        cout << -1 << "\n";
        return;
    }

    vector<int> copy = arr;
    sort(copy.begin(), copy.end());

    for (int i = 0; i < n-1; i++){
        if (arr[i] == copy[i]){
            swap(copy[i], copy[i+1]);
        }
    }

    if (copy[n-1] == arr[n-1]) swap(copy[n-1], copy[n-2]);

    for (auto &i : copy) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}