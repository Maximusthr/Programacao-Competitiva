#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    if (n % k == 0){
        cout << n/k << "\n";
        return;
    }

    set<int> fatores;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            fatores.insert(i);
            fatores.insert(n/i);
        }
    }

    vector<int> fact = {fatores.begin(), fatores.end()};

    int v = n/k;
    int maior = 1;
    for (int i = 0; i < fact.size(); i++){
        if (fact[i] > v){
            break;
        }
        else maior = max(maior, fact[i]);
    }

    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}