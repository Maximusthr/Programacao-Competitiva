#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    map<ll, ll> arr;
    for (int i = 0; i < n; i++){
        arr[a[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < m; i++){
        ans += arr[b[i]];
    }

    cout << ans << "\n";
}