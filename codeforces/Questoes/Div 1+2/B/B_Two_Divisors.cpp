#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

void solve(){
    ll a, b; cin >> a >> b;

    ll c = lcm(a, b);

    if (c != b) {
        cout << c << "\n";
        return;
    }

    ll menor = INF;
    for (ll i = 2; i * i <= a || i * i <= b; i++){
        if (a % i == 0){
            menor = min(menor, i);
            break;
        }
        if (b % i == 0){
            menor = min(menor, i);
            break;
        }
    }

    if (menor == INF) menor = b;

    cout << c * menor << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}