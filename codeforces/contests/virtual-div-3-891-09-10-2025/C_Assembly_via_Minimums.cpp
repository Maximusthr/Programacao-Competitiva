// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int v = n * (n-1)/2;

    vector<int> valores(v);
    for (auto &i : valores) cin >> i;

    sort(valores.begin(), valores.end());

    for (int i = 0; i < v; i += --n){
        cout << valores[i] << " ";
    }

    cout << valores.back();
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}