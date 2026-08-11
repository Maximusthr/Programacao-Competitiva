#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (is_sorted(arr.begin(), arr.end())){
        cout << 0 << "\n";
        return;
    }

    int w = 0;
    bool flag = false;
    for (int i = 0; i < n; i++){
        if (i+1 == arr[i] && w > arr[i]){
            cout << 2 << "\n";
            return;
        }
        if (i + 1 == arr[i]) {
            if (flag && w > 0){
                cout << 2 << "\n";
                return;
            }
            if (w > 0) flag = true;
            w = 0;
        }
        else w = max(w, arr[i]);
    }

    if (flag && w > 0){
        cout << 2 << "\n";
        return;
    }

    cout << 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}