#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, a, b, c; cin >> n >> a >> b >> c;

    int restante = n/(a+b+c);

    int ans = restante * 3;

    n -= (a+b+c)*restante;

    if (n <= 0){
        cout << ans << "\n";
        return;
    }
    else {
        n -= a;
        ans++;
        if (n <= 0){
            cout << ans << "\n";
            return;
        }

        n -= b;
        ans++;
        if (n <= 0){
            cout << ans << "\n";
            return;
        }

        n -= c;
        ans++;
        if (n <= 0){
            cout << ans << "\n";
            return;
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