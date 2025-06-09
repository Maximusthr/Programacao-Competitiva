// WA - TO-DO

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct dist {
    ll x, y, t;
    bool operator< (const dist& other) const {
        return t < other.t;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int g, n; cin >> g >> n;

    vector<dist> s(g);
    for (auto &[x, y, t] : s) cin >> x >> y >> t;
    
    sort(s.begin(), s.end());

    vector<dist> cows(n);
    for (auto &[x, y, t] : cows) cin >> x >> y >> t; 

    int ans = 0;
    for (int i = 0; i < n; i++){

        ll x = cows[i].x;
        ll y = cows[i].y;
        ll t = cows[i].t;

        // Caso de ir até o tempo maior
        auto it = lower_bound(s.begin(), s.end(), cows[i].t, [](const dist& d, ll T){return d.t < T;}) - s.begin();
        
        if (it == 0){
            ll d = abs(s[0].x - x) + abs(s[0].y - y);
            if (d > s[0].t - t) ans++;
        }
        
        else if (it == g){
            ll d = abs(s[g-1].x - x) + abs(s[g-1].y - y);
            if (d > t - s[g-1].t) ans++;
        }

        else {
            ll d1 = abs(s[it-1].x - x) + abs(s[it-1].y - y);
            ll d2 = abs(s[it].x - x) + abs(s[it].y - y);
            if (d1 > t - s[it-1].t || d2 > s[it].t - t) ans++;
        }
    }

    cout << ans << "\n";
}