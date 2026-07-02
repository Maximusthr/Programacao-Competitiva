#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<ll> retas(n);
    for (auto &i : retas) cin >> i;

    sort(retas.begin(), retas.end());

    struct eq {
        ll a, b, c;
    };

    vector<eq> parab(m);
    for (auto &i : parab) cin >> i.a >> i.b >> i.c;

    for (int i = 0; i < m; i++){
        ll delta = 4ll * parab[i].a * parab[i].c;

        ll idx = lower_bound(retas.begin(), retas.end(), parab[i].b) - retas.begin();
        if (idx < n){
            ll new_b = (parab[i].b - retas[idx]) * (parab[i].b - retas[idx]);
            if (new_b < delta){
                cout << "YES" << "\n";
                cout << retas[idx] << "\n";
                continue;
            }
        }

        idx--;
        if (idx >= 0 && (parab[i].b - retas[idx]) * (parab[i].b - retas[idx]) < delta){
            cout << "YES" << "\n";
            cout << retas[idx] << "\n";
            continue;
        }

        cout << "NO" << "\n";
    }
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}