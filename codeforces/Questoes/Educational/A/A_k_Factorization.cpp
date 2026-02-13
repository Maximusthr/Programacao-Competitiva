#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 100005;

vector<int> crivo;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> factor;
    while(n > 1){
        factor.push_back(crivo[n]);
        n /= crivo[n];
    }

    if (factor.size() < k){
        cout << -1 << "\n";
        return;
    }

    int aux = 0;
    for (int i = 0; i < factor.size(); i++){
        if (aux != k-1){
            cout << factor[i] << " ";
            aux++;
        }
        else{   
            int v = 1;
            while (i < factor.size()){
                v *= factor[i];
                i++;
            }
            cout << v << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    crivo.resize(MAX);

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

    solve();
}