#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    ll k; cin >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    auto ok = [&](int mid) -> bool {
        // começo do primeiro
        // dai eu preciso intercalar pra saber quantos ataques foram
        
        // mid = qtd navios que afundaram
        ll v = 0; // k 

        vector<ll> copy = arr;

        bool alter = false;

        int af = 0;

        int i = 0, j = n-1;
        while(i <= j && v <= k){
            ll ini = copy[i];
            ll last = copy[j];

            ll val = min(ini, last);

            if (i == j){
                if (copy[i] + v <= k){
                    af++;
                    break;
                }
            }

            if (!alter){
                // começamos do primeiro

                if (val == ini){
                    v += 2 * val - 1;
                    if (v > k) break;
                    copy[j] -= (copy[i]-1);
                    i++;
                    alter ^= 1;
                }
                else {
                    v += 2 * val;
                    if (v > k) break;
                    copy[i] -= (copy[j]);
                    j--;
                }
                af++;
            }
            else {
                // começamos do ultimo
                if (val == last){
                    v += 2 * val - 1;
                    if (v > k) break;
                    copy[i] -= (copy[j]-1);
                    j--;
                    alter ^= 1;
                }
                else {
                    v += 2 * val;
                    if (v > k) break;
                    copy[j] -= (copy[i]);
                    i++;
                }
                af++;
            }
        }


        return (af >= mid);
    };

    int l = 0, r = n;
    while(l < r){
        int mid = l + (r-l+1)/2;

        if (ok(mid)) l = mid;
        else r = mid - 1;
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