#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    if (k > 50){
        cout << 0 << "\n";
        return;
    }
    
    auto ok = [&](int a, int b, int m) -> int {
        vector<ll> fib(m+2);

        fib[m] = b;
        fib[m-1] = a;

        for (int i = m - 2; i > 0; i--){
            fib[i] = fib[i+2] - fib[i+1];
        }

        for (int i = 1; i <= m; i++){
            if (fib[i] < 0 || fib[i] < fib[i-1]) return 0;
        }

        return 1;
    };

    int ans = 0;
    for (int i = 0; 2*i <= n; i++){
        ans += ok(i, n - i, k-1);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}