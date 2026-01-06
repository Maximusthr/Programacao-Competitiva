#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (auto &i : arr) cin >> i;

    vector<int> prefix(n+1), suffix(n+2);

    for (int i = 1; i <= n; i++){
        prefix[i] = __gcd(prefix[i-1], arr[i-1]);
    }
    for (int i = n; i >= 1; i--){
        suffix[i] = __gcd(suffix[i+1], arr[i-1]);
    }

    vector<int> divs;
    for (int i = 1; i <= n; i++){
        divs.push_back(__gcd(prefix[i-1], suffix[i+1]));
    }
    
    ll ans = 1;
    for (int i = 0; i < n; i++){
        ans = lcm(ans, divs[i]);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}