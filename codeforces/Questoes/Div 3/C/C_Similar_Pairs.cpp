#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] % 2) odd++;
        else even++;
    }
    
    if (odd % 2 == 0 && even % 2 == 0){
        cout << "YES" << "\n";
        return;
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1 ; j < n; j++){
            if (arr[i] + 1 == arr[j] || arr[i]-1 == arr[j]){
                cout << "YES" << "\n";
                return;
            }
        }
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