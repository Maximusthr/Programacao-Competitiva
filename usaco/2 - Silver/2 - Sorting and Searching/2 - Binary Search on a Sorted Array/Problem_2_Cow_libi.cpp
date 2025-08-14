#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct dist {
    int x, y, t;
    bool operator< (const dist& other) const {
        return t < other.t;
    }
};

bool reach(dist g1, dist g2){
    long long dt = g1.t - g2.t;
    long long dx = g1.x - g2.x;
    long long dy = g1.y - g2.y;

    return dt * dt < dx * dx + dy * dy;
}

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
        bool ok = true;

        auto it = lower_bound(s.begin(), s.end(), cows[i].t, [](const dist &d, int T){
            return d.t < T;
        });

        if (it != s.end()){
            if (reach(cows[i], *it)){
                ok = false;
            }
        }
        if (it > s.begin()){
            if (reach(cows[i], *(it-1))){
                ok = false;
            }
        }

        if (!ok) ans++;
    }

    cout << ans << "\n";
}