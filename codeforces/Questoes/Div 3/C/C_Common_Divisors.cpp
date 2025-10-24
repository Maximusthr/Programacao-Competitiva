#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll gccd = 0;
    for (int i = 0; i < n; i++){
        gccd = __gcd(arr[i], gccd);
    }

    int ans = 0;
    for (ll i = 1; i * i <= gccd; i++){        
        if (gccd % i == 0){
            ans += i * i == gccd ? 1 : 2;
        }
    }

    cout << ans << "\n";
}