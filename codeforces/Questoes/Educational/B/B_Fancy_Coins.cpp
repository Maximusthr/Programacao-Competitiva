#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int m, k, a1, ak; cin >> m >> k >> a1 >> ak;

    if (a1 >= m){
        cout << 0 << "\n";
        return;
    }

    if (k > m){
        m -= a1;
        cout << m << "\n";
        return;
    }

    if (m % k == 0){
        int l = 0, r = 1e8;
        while(l < r){
            int mid = l + (r-l+1)/2;

            if (1ll * mid * k <= a1){
                l = mid;
            }
            else r = mid - 1;
        }
        m -= l * k;
        cout << max(0, m/k - ak) << "\n";
    }
    else {
        int x = m % k;
        m -= x;
        a1 -= x;

        int ans = 0;
        if (a1 < 0) {
            ans += abs(a1);
        }
        else {
            int l = 0, r = 1e8;
            while(l < r){
                int mid = l + (r-l+1)/2;

                if (1ll * mid * k <= a1){
                    l = mid;
                }
                else r = mid - 1;
            }
            m -= l * k;
        }
        cout << ans + max(0, m/k - ak) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}