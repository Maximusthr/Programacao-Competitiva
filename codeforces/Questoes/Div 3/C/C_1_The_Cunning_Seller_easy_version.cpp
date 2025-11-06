#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll exp(ll a, ll b){
    ll x = 1;
    while(b > 0){
        if (b % 2) x *= a;
        a *= a;
        b >>=1;
    }
    return x;
}

vector<ll> valor;
map<ll, ll> custo;

void solve(){
    ll n; cin >> n;

    ll money = 0;
    while (n > 0){
        auto it = upper_bound(valor.begin(), valor.end(), n);
        it--;

        money += custo[*it];

        n -= *it;
    }

    cout << money << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    for (int i = 0; i < 21; i++){
        ll k = exp(3, i);
        valor.push_back(k);

        ll v = exp(3, i+1) + i * exp(3, i-1);
        custo[k] = v;
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}