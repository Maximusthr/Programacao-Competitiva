#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n); 
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];

        if (arr[i] % 2) odd++;
        else even++;
    }

    if (odd % 2 == 0) odd--;

    if (odd >= 1 && odd + even >= k) {
        if (k % 2 == 0 && even == 0){
            cout << "No" << "\n";
        }
        else cout << "Yes" << "\n";
    }
    else cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}