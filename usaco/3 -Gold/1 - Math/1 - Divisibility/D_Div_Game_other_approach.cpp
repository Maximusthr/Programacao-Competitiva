#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;
    
    int ans = 0;
    for (ll i = 2; i * i <= n; i++){
        int cur = 0;

        while(n % i == 0){
            n /= i;
            cur++;
        }

        for (int j = 1; cur - j >= 0; j++){
            ans++;
            cur -= j;
        }
    }

    if (n > 1) ans++;
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}