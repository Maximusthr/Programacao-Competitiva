#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll b; cin >> b;
    
    // ans = (b)/gcd(a, b)
    // a up to 10^18

    int ans = 0;
    for (ll i = 1; i * i <= b; i++){
        if (b % i == 0){
            ans += (i * i == b ? 1 : 2); 
        }
    }

    cout << ans << "\n";
}