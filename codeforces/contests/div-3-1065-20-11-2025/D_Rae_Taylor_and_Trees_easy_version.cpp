// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+2);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> prefix(n+1), suffix(n+2);
    prefix[0] = INF;

    for (int i = n; i > 0; i--){
        suffix[i] = max(suffix[i+1], arr[i]);
    }
    for (int i = 1; i <= n; i++){
        prefix[i] = min(prefix[i-1], arr[i]);
    }

    for (int i = 2; i <= n; i++){
        if (prefix[i-1] > suffix[i]){
            cout << "No" << "\n";
            return;
        }
    }

    cout << "Yes" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}