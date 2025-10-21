#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string func(int n, int m, int k, bool ok){
    // a é maior
    // b é menor

    char a = (ok ? '0' : '1');
    char b = (!ok ? '0' : '1');

    string s; 

    for (int i = 0; i < k; i++){
        s += a;
    }

    int eq = k;
    int aux_n = k, aux_m = 0;
    for (int i = s.size(); i < n+m; i++){
        if (eq == k || aux_n == n) {
            s += b;
            aux_m++;
            eq--;
        }
        else if (aux_n < n) {
            s += a;
            aux_n++;
            eq++;
        }
    }

    return s;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;

    if (max(n-m, m-n) > k || max(n, m) < k) {
        cout << -1 << "\n";
        return;
    }

    bool ok = (n > m);

    string ans = func(max(n, m), min(n, m), k, ok);
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}