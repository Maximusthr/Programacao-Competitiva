#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;

    map<ll, int> freq;
    for (ll i = 2; i * i <= n; i++){
        while (n % i == 0){
            freq[i]++;
            n /= i;
        }
    }
    if (n > 1) freq[n]++;

    pair<ll, int> maior = {0, 0};
    for (auto [x, y] : freq){
        if (y > maior.second){
            maior = {x, y};
        }
    }

    ll v = 1;
    for (auto [x, y] : freq){
        if (x == maior.first) continue;
        else v *= pow(x, y);
    }

    v *= maior.first;

    cout << (maior.second - 1) + (v > 1 ? 1 : 0) << "\n";
    for (int i = 0; i < maior.second - 1; i++){
        cout << maior.first << " ";
    }
    if (v > 1) cout << v << "\n";
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}