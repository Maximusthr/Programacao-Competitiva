#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, m; cin >> n >> m;
    if (n < m){
        cout << 0 << "\n";
        return;
    }
    
    vector<int> digit;
    int ini = m % 10;
    digit.push_back(ini);

    ll aux = m+m;
    while(aux%10 != ini && aux <= n){
        digit.push_back(aux % 10);
        aux += m;
    }

    ll v = n/m;

    int resto = v % digit.size();
    v /= (int) digit.size();

    ll ans = 0;
    for (int i = 0; i < digit.size(); i++){
        ans += v * digit[i];
        if (i < resto) ans += digit[i];
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}