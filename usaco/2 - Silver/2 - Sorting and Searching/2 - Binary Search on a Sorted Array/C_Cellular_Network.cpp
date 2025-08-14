#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<ll> city(n);
    vector<ll> tower(m);

    for (auto &i : city) cin >> i;
    for (auto &i : tower) cin >> i;

    ll ans = 0;
    for (int i = 0; i < n; i++){

        int l = 0, r = tower.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;

            if (tower[mid] > city[i]){
                r = mid;
            }
            else l = mid + 1;
        }

        int temp = l;

        l = 0, r = tower.size()-1;
        while(l < r){
            int mid = l + (r-l+1)/2;

            if (tower[mid] <= city[i]){
                l = mid;
            }
            else r = mid - 1;
        }

        ans = max(ans, min(abs(tower[temp] - city[i]), abs(tower[l] - city[i])));
    }

    cout << ans << "\n";
}