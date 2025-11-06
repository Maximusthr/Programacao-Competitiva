#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    k--;

    // o diametro deve ser estritamente menor que k
   
    if (m > n * (n-1)/2 || m < n-1){
        cout << "NO" << "\n";
        return;
    }

    if (k == 1 && n == 1 && m == 0){
        cout << "YES" << "\n";
        return;
    }
    if (k == 2 && m == n * (n-1)/2){
        cout << "YES" << "\n";
        return;
    }
    if (k >= 3){
        cout << "YES" << "\n";
        return;
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}