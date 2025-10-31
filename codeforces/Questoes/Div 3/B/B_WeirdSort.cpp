#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    vector<bool> p(n+1);
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        p[x] = true;
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j > 0; j--){
            if (arr[j] < arr[j-1]){
                if (p[j]) swap(arr[j], arr[j-1]);
                else {
                    cout << "NO" << "\n";
                    return;
                }
            }
        }
    }

    if (is_sorted(arr.begin(), arr.end())){
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}