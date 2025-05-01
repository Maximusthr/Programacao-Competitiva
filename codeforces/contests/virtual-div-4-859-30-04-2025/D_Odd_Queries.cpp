#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, q; cin >> n >> q;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        // prefix-sum
        for (int i = 1; i < n; i++){
            arr[i] += arr[i-1];
        }

        while(q--){
            int l, r, k; cin >> l >> r >> k;

            int dif = 0;
            if (l == 1) dif = arr[r-1];
            else dif = arr[r-1] - arr[l-2];

            int val = k * (r-l+1);
            if ((arr[n-1] - dif + val) % 2) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}
