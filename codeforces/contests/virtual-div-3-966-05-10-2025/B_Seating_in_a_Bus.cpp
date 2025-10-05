#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<bool> arr(n+1);

    vector<int> v(n);
    for (auto &i : v) cin >> i;

    for (int i = 0; i < n; i++){
        if (i == 0){
            arr[v[i]] = true;
            continue;
        }

        if (v[i] == 1){
            if (!arr[v[i]+1]){
                cout << "NO" << "\n";
                return;
            }
        }
        if (v[i] == n){
            if (!arr[v[i]-1]){
                cout << "NO" << "\n";
                return;
            }
        }
        if (!arr[v[i]-1] && !arr[v[i]+1]){
            cout << "NO" << "\n";
            return;
        }

        arr[v[i]] = true;
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