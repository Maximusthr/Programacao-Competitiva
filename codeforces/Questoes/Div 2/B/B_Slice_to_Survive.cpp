#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, a, b; cin >> n >> m >> a >> b;

    auto func = [&](int x) -> int {
        int ans = 0;
        while (x > 1){
            x = (x + 1)/2;
            ans++;
        }
        return ans;
    };

    auto ans = [&](int x, int y) -> int {
        return (func(x) + func(y));
    };

    cout << 1 + min({ans(a, m), ans(n-a+1, m), ans(n, b), ans(n, m-b+1)}) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}