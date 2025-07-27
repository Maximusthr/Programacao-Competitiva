#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    if (n == 1){
        cout << 0 << "\n";
        return;
    }

    vector<int> div;
    for (int i = 1; i*i <= n; i++){
        if (n % i == 0){
            if (n/i == i){
                div.push_back(i);
            }
            else {
                div.push_back(i);
                div.push_back(n/i);
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < div.size(); i++){
        if (div[i] == n) continue;
        
        int aux = 0;
        ll temp = 0;
        ll maior = -LINF;
        ll menor = LINF;
        int atual = div[i];
        
        for (int i = 0; i < n; i++){
            temp += arr[i];
            aux++;
            if (aux == atual){
                maior = max(maior, temp);
                menor = min(menor, temp);
                aux = 0;
                temp = 0;
            }
        }
        ans = max(maior-menor, ans);
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