#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve
void solve(){
    int n, m; cin >> n >> m;
    if (n > m || (n == 0 && m % 2 == 0)){
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
    if ((n + m) % 2 == 0){
        // raiz é par
        int even = 1;
        int odd = 0;
        for (int i = 1; even < n; i++){
            cout << i << " " << i + 1 << "\n";
            if (i % 2 == 0) even++;
            else odd++;
        }
        for (int i = odd + even + 1; i <= n + m; i++){
            cout << 1 << " " << i << "\n";
        }
    }
    else {
        // raiz é impar
        int even = 0;
        int odd = 1;
        
        for (int i = 1; even < n; i++){
            cout << i << " " << i+1 << "\n";
            if (i % 2 == 0) even++;
            else odd++;
        }

        for (int i = odd + even + 1; i <= n + m; i++){
            cout << 1 << " " << i << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}