#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;

    set<ll> valores;
    for (ll i = 2; i * i <= n; i++){
        if (valores.count(i)) continue;

        ll aux = i;
        while (aux * i <= n){
            aux = (aux * i);
            valores.insert(aux);
        }
    }

    cout << n - valores.size() << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}