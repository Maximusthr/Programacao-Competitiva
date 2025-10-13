#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll lcm(ll a, ll b){
    return a * (b/__gcd(a, b));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll n; cin >> n;

    ll ans = 0;
    for (ll i = 1; i * i <= n; i++){
        if (n % i == 0){
            if (lcm(i, n/i) == n){
                ans = i;
            }
        }
    }

    cout << ans << " " << n/ans << "\n";
}