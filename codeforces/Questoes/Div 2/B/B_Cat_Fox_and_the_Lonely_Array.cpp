#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<vector<int>> prefix(n, vector<int> (21));

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= 20; j++){
            if (arr[i] & (1 << j)) prefix[i][j] = 1;
            if (i > 0) prefix[i][j] += prefix[i-1][j];
        }
    }

    int o = 0;
    for (int i = 0; i < n; i++){
        o |= arr[i];
    }

    auto ok = [&](int mid) -> bool {
        int v = o;
        for (int i = 0; i < n; i++){
            if (i + mid > n) break;
            
            int aux = 0;
            for (int j = 0; j <= 20; j++){
                if (prefix[i + mid - 1][j] - (i ? prefix[i-1][j] : 0) > 0) aux |= (1 << j);
            }

            if (aux != v){
                return false;
            }  
        }
        return true;
    };

    int l = 1, r = n;
    while(l < r){
        int mid = (l+r)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}