#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    
    int ans = 0;
    while(n > 0 && m > 0){
        if (n > m){
            n -= 2;
            m--;
            ans++;
        }
        else {
            if (n == 1 && m == 1) break;
            m -= 2;
            n--;
            ans++;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}