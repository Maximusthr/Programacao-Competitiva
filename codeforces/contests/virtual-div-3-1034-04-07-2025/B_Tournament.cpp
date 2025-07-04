#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, j, k; cin >> n >> j >> k;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    if (k >= 2) {
        cout << "YES" << "\n";
        return;
    }

    if (k == 1){
        int alvo = arr[j];
        for (int i = 1; i <= n; i++){
            if (alvo < arr[i]){
                cout << "NO" << "\n";
                return;
            }
        }
        cout << "YES" << "\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}