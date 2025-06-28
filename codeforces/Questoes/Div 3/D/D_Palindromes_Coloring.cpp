#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;
    map<char, int> letras;

    for (int i = 0; i < n; i++){
        letras[s[i]]++;
    }

    int even = 0, odd = 0;
    for (auto [x, y] : letras){
        even += y/2;
        if (y % 2) odd++;
    }

    int ans = 2 * (even/k);
    odd += 2 * (even % k);
    if (odd >= k) ans++;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}