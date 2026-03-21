#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n-1; i++){
        ll v = arr.back() - arr[i];
        v /= k;
        v *= k;
        arr[i] += v;
    }

    sort(arr.begin(), arr.end());

    ll ans = arr.back() - arr.front();

    multiset<ll> menores = {arr.begin(), arr.end()};

    for (int i = 0; i < n; i++){
        menores.erase(menores.find(arr[i]));
        arr[i] += k;
        menores.insert(arr[i]);
        
        ll valor = *menores.begin();
        ll maiorzao = *menores.rbegin();

        ans = min(maiorzao - valor, ans);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}