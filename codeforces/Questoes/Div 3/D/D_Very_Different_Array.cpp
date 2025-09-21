#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<ll> a(n);
    for (auto &i : a) cin >> i;

    vector<ll> b(m);
    for (auto &i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    int l = 0, r = m-1;
    for (int i = 0, j = n-1; i < n && l < m && r >= 0 && j >= 0 && l <= r && i <= j; ){
        ll left_l = abs(a[i] - b[l]);
        ll right_l = abs(a[i] - b[r]);

        ll left_r = abs(a[j] - b[l]);
        ll right_r = abs(a[j] - b[r]);

        if (left_r >= right_r){
            if (left_r >= left_l && left_r >= right_l){
                ans += left_r;
                j--;
                l++;
            }
            else{
                if (left_l >= right_l){
                    ans += left_l;
                    i++;
                    l++;
                }
                else {
                    ans += right_l;
                    i++;
                    r--;
                }
            }
        }
        else {
            if (right_r >= left_l && right_r >= right_l){
                ans += right_r;
                j--;
                r--;
            }
            else{
                if (left_l >= right_l){
                    ans += left_l;
                    i++;
                    l++;
                }
                else {
                    ans += right_l;
                    i++;
                    r--;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}