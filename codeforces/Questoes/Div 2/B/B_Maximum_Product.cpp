#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> pos, neg;
    bool zero = false;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        if (x > 0) pos.push_back(x);
        else if (x < 0) neg.push_back(x);
        if (!x) zero = 1;
    }

    // coner case =)))))))))))))))))))))

    if (neg.size() + pos.size() <= 4){
        cout << 0 << "\n";
        return;
    }

    if (pos.size() == 0){
        if (zero) cout << 0 << "\n";
        else {
            sort(neg.begin(), neg.end(), greater<int> ());
            cout << neg[0] * neg[1] * neg[2] * neg[3] * neg[4] << "\n";
        }
        return;
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end(), greater<ll>());

    if ((int)neg.size() + (int)pos.size() == 5){
        ll v = 1;
        for (int i = 0; i < neg.size(); i++) v *= neg[i];
        for (int i = 0; i < pos.size(); i++) v *= pos[i];

        if (v < 0 && zero) cout << 0 << "\n";
        else cout << v << "\n";
        return;
    }

    ll v = 1;
    if (neg.size() >= 2 && pos.size() >= 3){
        v *= neg[0] * neg[1];
        v *= pos[0] * pos[1] * pos[2];
    }

    if (neg.size() >= 4 && pos.size() > 0){
        ll aux = neg[0] * neg[1] * neg[2] * neg[3] * pos[0];
        v = max(v, aux);
    }

    if (pos.size() >= 5){
        ll aux = pos[0] * pos[1] * pos[2] * pos[3] * pos[4];
        v = max(v, aux); 
    }

    if (zero && v < 0) cout << 0 << "\n";
    else cout << v << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}