#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int a, b, c, d; cin >> a >> b >> c >> d;

        int ans = 0;
        if (b > a) ans++;
        if (c > a) ans++;
        if (d > a) ans++;

        cout << ans << "\n";
    }
}