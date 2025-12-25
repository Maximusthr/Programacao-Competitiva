#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int even = arr[0], odd = arr[1];
    for (int i = 2; i < n; i++){
        if (i % 2 == 0){
            if ((even % 2 && arr[i] % 2 == 0) || (even % 2 == 0 && arr[i] % 2)){
                cout << "NO" << "\n";
                return;
            }
        }
        else {
            if ((odd % 2 && arr[i] % 2 == 0) || (odd % 2 == 0 && arr[i] % 2)){
                cout << "NO" << "\n";
                return;
            }
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}