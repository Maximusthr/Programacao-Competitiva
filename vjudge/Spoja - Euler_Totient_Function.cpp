#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;

vector<int> phi;

void solve(){
    int n; cin >> n;

    cout << phi[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    phi.resize(MAX);
    for (int i = 0; i < MAX; i++){
        phi[i] = i;
    }

    for (int i = 2; i < MAX; i++){
        if (phi[i] == i){
            for (int j = i; j < MAX; j += i){
                phi[j] -= phi[j]/i;
            }   
        }
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}