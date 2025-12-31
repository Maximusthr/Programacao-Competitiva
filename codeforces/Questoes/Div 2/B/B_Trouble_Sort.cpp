#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    int um = 0, zero = 0;
    vector<int> b(n);
    for (auto &i : b) {
        cin >> i;
        if (i == 0) zero++;
        else um++;
    }
    
    if (is_sorted(arr.begin(), arr.end())){
        cout << "Yes" << "\n";
        return;
    }

    if (zero > 0 && um > 0){
        cout << "Yes" << "\n";
        return;
    }

    cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}