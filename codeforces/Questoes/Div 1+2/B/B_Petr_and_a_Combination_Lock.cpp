#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < (1 << n); i++){
        int sum = 0;
        for (int j = 0; j < n; j++){
            if (i & (1 << j)){
                sum += arr[j];
            }
            else sum -= arr[j];
        }

        if (((sum % 360) + 360) % 360 == 0){
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}