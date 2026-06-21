#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e7+1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    vector<int> phi(MAX);

    for (int i = 1; i < MAX; i++){
        phi[i] = i;
    }
    
    for (ll i = 2; i < MAX; i++){
        if (phi[i] == i){
            phi[i] = i;
            for (ll j = i; j < MAX; j += i){
                phi[j] -= phi[j]/i;
            }
        }
    }

    vector<ll> sum(MAX, 0);
    for (ll i = 1; i < MAX; i++){
        ll term = i * phi[i];
        for (ll j = i; j < MAX; j += i){
            sum[j] += term;
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        cout << sum[n] << "\n";
    }
}
