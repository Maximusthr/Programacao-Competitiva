#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, l, r, x; cin >> n >> l >> r >> x;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++){
        vector<int> conj;
        for (int bit = 0; bit < n; bit++){
            if (mask & (1 << bit)){
                conj.push_back(arr[bit]);
            }
        }

        int sum = accumulate(conj.begin(), conj.end(), 0);
        if (sum >= l && sum <= r){
            if (abs(conj[0] - conj[conj.size() - 1]) >= x){
                ans++;
            }
        }
    }

    cout << ans << "\n";
}