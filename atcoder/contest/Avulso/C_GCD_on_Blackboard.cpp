#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<ll> arr(n+1);

    vector<ll> prefix(n+1);
    vector<ll> sufix(n+2);

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++){
        prefix[i] = __gcd(prefix[i-1], arr[i]);
    }
    for (int i = n; i > 0; i--){
        sufix[i] = __gcd(sufix[i+1], arr[i]);
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++){
        ans = max(ans, __gcd(prefix[i-1], sufix[i+1]));
    }

    cout << ans << "\n";
}
