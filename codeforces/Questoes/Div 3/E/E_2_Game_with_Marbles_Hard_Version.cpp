#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct v {
    ll soma, a, b;
};

void solve(){
    int n; cin >> n;

    vector<ll> a, b;
    
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        a.push_back(x);    
    }
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        b.push_back(x);
    }
    
    vector<v> jogo;
    
    for (int i = 0; i < n; i++){
        jogo.push_back({a[i] + b[i], a[i], b[i]});
    }

    sort(jogo.begin(), jogo.end(), [&](v x, v y){
        if (x.soma != y.soma){
            return x.soma > y.soma;
        }
        if (x.a != y.a){
            return x.a > y.a;
        }
        return x.b > y.b;
    });

    ll ans = 0;

    for (int i = 0; i < n; i++){
        if (i % 2 == 0) ans += jogo[i].a - 1;
        else ans -= jogo[i].b - 1;
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