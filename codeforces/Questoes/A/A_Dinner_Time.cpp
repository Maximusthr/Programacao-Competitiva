#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, m, p, q; cin >> n >> m >> p >> q;

        if (n % p == 0){
            if (n/p * q == m) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
        else cout << "YES" << "\n";
    }
}
