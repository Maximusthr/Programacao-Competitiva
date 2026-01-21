#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5e6 + 5;

vector<int> crivo;
vector<int> fatores;
vector<ll> prefix;

void solve(){
    int a, b; cin >> a >> b;
    cout << prefix[a] - prefix[b] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    crivo.resize(MAX);
    fatores.resize(MAX);
    prefix.resize(MAX);

    crivo[0] = 0;
    crivo[1] = 1;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i] == 0){
            crivo[i] = i;
            for (ll j = i * i; j < MAX; j += i){
                if (crivo[j] == 0){
                    crivo[j] = i;
                }
            }
        }
    }

    fatores[1] = 1;
    for (int i = 2; i < MAX; i++){
        int aux = i;
        while(aux > 1){
            fatores[i]++;
            aux /= crivo[aux];
        }
    }

    for (int i = 1; i < MAX; i++){
        prefix[i] = prefix[i-1] + fatores[i];
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}