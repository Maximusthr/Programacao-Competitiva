#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// UPSOLVE =(

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (arr[0] == 0) {
        cout << arr[0] << "\n";
        return;
    }

    if (arr.size() == 2){
        cout << arr[0] + min(arr[0], arr[1]) << "\n";
        return;
    }
    if (arr[1] == 0){
        cout << arr[0] << "\n";
        return;
    }

    //This was the problem
    // if (arr.size() > 2){
    //     arr[1] += arr[2];
    //     arr[2] = 0;
    // }
    cout << arr[0] + min(arr[0], arr[1]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}