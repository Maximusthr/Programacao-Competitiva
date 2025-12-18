// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(m);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ciclo = 0;
    int idx_l = 0;
    int idx_r = m-1;
    bool alter = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            if (!alter) cout << arr[idx_l] << " " << arr[idx_r] << " ";
            else cout << arr[idx_r] << " " << arr[idx_l] << " ";
        }

        alter ^= 1;
        if ((i+1) % 2 == 0){
            idx_l++;
            idx_r--;
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}