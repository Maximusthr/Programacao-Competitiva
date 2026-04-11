#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<double> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++){
        double v = 0.5;
        int aux = 0;
        for (int bit = 0; bit < n; bit++){
            if (mask & (1 << bit)){
                if (v < 0){
                    v += arr[bit];
                    if (v > 0) aux++;
                }
                else v += arr[bit];
            }
            else {
                if (v > 0){
                    v -= arr[bit];
                    if (v < 0) aux++;
                }
                else v -= arr[bit];
            }
        }
        ans = max(ans, aux);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}