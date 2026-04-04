#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
// upsolve
const int MAX = 1e6+5;
vector<int> crivo(MAX, true);
vector<ll> prime;

void solve(){
    int n; cin >> n;

    cout << 1 << " ";
    for (int i = 0; i < n-1; i++){
        cout << prime[i] * prime[i+1] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);


    crivo[0] = 0;
    crivo[1] = 0;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i]){
            prime.push_back(i);
            for (ll j = i * i; j < MAX; j += i){
                crivo[j] = false;
            }
        }
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}