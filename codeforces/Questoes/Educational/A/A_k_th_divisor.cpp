#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k; cin >> n >> k;
    
    set<ll> fat;

    for (ll i = 1; i * i <= n; i++){
        if (n % i == 0){
            fat.insert(i);
            fat.insert(n/i);
        }
    }

    vector<ll> fact = {fat.begin(), fat.end()};

    if (k > fact.size()) cout << -1 << "\n";
    else cout << fact[k-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}