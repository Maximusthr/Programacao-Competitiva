#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;
vector<int> crivo;

void solve(){
    int n, m; cin >> n >> m;

    if (m == 1){
        cout << "YES" << "\n";
        return;
    }

    if (n % m == 0){
        cout << "NO" << "\n";
        return;
    }

    if (n != 1 && m > n){
        cout << "NO "<< "\n";
        return;
    }

    
    // preciso ver se existe um m tal que k * m == n -> se existir é falso
    
    set<int> fatores;

    while (n > 1){
        fatores.insert(crivo[n]);
        n /= crivo[n];
    }

    for (auto it : fatores){
        if (m > it){
            cout << "NO "<< "\n";
            return;
        }
    }    

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    crivo.resize(MAX);

    crivo[0] = 0;
    crivo[1] = 0;

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

    int t; cin >> t;
    while(t--){
        solve();
    }
}