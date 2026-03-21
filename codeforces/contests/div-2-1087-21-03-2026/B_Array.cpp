#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < n; i++){
        ll ans = 0, ans2 = 0;
        ll maior = -LINF;
        ll menor = LINF;
        vector<ll> aux = arr, aux2 = arr;
        for (int j = i + 1; j < n; j++){
            maior = max(arr[j], maior);
            menor = min(arr[j], menor);
        }

        for (int j = i + 1; j < n; j++){
            aux[j] = abs(aux[j] - maior);
            aux2[j] = abs(aux2[j] - menor);
        }

        for (int j = i + 1; j < n; j++){
            if (abs(arr[i] - maior) > aux[j]) ans++;
            if (abs(arr[i] - menor) > aux2[j]) ans2++;
        }

        cout << max(ans, ans2) << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}