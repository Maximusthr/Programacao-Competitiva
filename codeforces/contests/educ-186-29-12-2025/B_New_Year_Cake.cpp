#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int func(int a, int b, int pot){
    // a começa em cima
    int ans = 0;
    bool alter = false;
    while (a >= 0 && b >= 0){
        if (!alter){
            a -= pot;
            if (a < 0) break;
            ans++;
        }
        else {
            b -= pot;
            if (b < 0) break;
            ans++;
        }
        pot <<= 1;
        alter ^= 1;
    }
    
    return ans;
}

void solve(){
    int a, b; cin >> a >> b;

    int pot = 1;
    cout << max(func(a, b, pot), func(b, a, pot)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}