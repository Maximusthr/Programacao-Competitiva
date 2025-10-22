#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll lcm(ll a, ll b) {
    return a/__gcd(a, b) * b;
}

void solve(){
    int n; cin >> n;

    int aux = n;

    vector<int> primos;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            primos.push_back(i);
            primos.push_back(n/i);
            n /= i;
        }
    }
    if (n > 1) primos.push_back(n);

    ll ans = LINF;
    pair<int, int> talvez;
    for (int i = 0; i < primos.size(); i++){
        if (lcm(primos[i], aux-primos[i]) < ans){
            talvez = {primos[i], aux-primos[i]};
            if (aux-primos[i] == 0){
                talvez.second = 1;
            }
            if (talvez.first == aux) talvez.first--;

            ans = lcm(primos[i], aux-primos[i]);
        }
    }

    cout << talvez.first << " " << talvez.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}