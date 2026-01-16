#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    map<ll, bool> freq;

    for (auto &i : arr) {
        cin >> i;
        freq[i] = true;
    }

    sort(arr.begin(), arr.end());

    vector<int> pulos;
    int gcdd = 0;
    for (int i = 0; i < n-1; i++){
        pulos.push_back(abs(arr[i+1] - arr[i]));
        gcdd = __gcd(gcdd, pulos[i]);
    }

    if (pulos.size() == 0){
        cout << 1 << "\n";
        return;
    }

    ll ans = 0;

    ll maior = arr.back();

    for (int i = 0; i < n; i++){
        ans += abs((maior - arr[i]))/gcdd;
    }

    ll aux = n;

    // pode ser negativo lol

    bool fim = false;

    ll talvez = maior-gcdd;
    while(freq[talvez]){
        talvez -= gcdd;
    }

    ans += min(1ll*(maior-talvez)/gcdd, 1ll*n);
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}