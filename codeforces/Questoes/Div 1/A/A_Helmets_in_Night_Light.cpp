#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, p; cin >> n >> p;

    vector<pair<ll, ll>> a(n);
    for (auto &i : a) cin >> i.first;
    for (auto &i : a) cin >> i.second;

    sort(a.begin(), a.end(), [&](pair<int, int> x, pair<int, int> y){
        if (x.second != y.second) return x.second < y.second;
        return x.first > y.first;
    });

    ll ans = 0;
    vector<bool> foi(n);
    set<int> falta;
    for (int i = 0; i < n; i++){
        falta.insert(i);
    }
    for (int i = 0, j = n-1; i <= j; i++){
        if (falta.size() == 0){
            break;
        }

        if (!foi[i]){
            ans += p;
            foi[i] = true;
            falta.erase(i);
        }
        if (a[i].second < p){
            while(a[i].first > 0 && falta.size() > 0){
                ans += a[i].second;
                foi[*falta.begin()] = true;
                falta.erase(*falta.begin());
                a[i].first--;
            }
        }

        if (falta.size() == 0) break;
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