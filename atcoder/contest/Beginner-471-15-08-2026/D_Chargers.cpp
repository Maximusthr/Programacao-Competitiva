#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

void solve(){
    ll n, v; cin >> n >> v;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        if (a == 2){
            ll t; cin >> t;

            if (pq.empty()) {
                cout << -1 << "\n";
            }
            else {
                int x = pq.top();
                pq.pop();
                cout << min(v, x + t) << "\n";
            }
        }
        else {
            ll t, c; cin >> t >> c;
            pq.push(c - t);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
