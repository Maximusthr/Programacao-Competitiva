#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll n, k; cin >> n >> k;

    vector<ll> arr(k);
    for (auto &i : arr) cin >> i;

    ll menor = LINF;
    int pos = 0;
    ll qtd = 0;
    for (int i = 0; i < k; i++){
        ll aux = n/arr[i];

        if (n - arr[i]*aux <= menor){
            menor = n - arr[i]*aux;
            pos = i;
            qtd = aux;
        }
    }

    cout << pos+1 << " " << qtd << "\n";
}
