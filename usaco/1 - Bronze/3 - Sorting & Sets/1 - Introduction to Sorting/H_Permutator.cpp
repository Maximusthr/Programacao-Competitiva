#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    a[0] *= n;
    a[n-1] *= n;
    for (int i = 1; i < n-1; i++){
        a[i] = a[i] * (n-i) * (i+1);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll> ());
    
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += a[i] * b[i];
    }

    cout << ans << "\n";
}
