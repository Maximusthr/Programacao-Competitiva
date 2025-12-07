#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    vector<ll> total;
    for (auto [x, y] : freq){
        total.push_back(y);
    }

    vector<ll> prefix(total.size() + 1);
    for (int i = 1; i <= total.size(); i++){
        prefix[i] += prefix[i-1] + total[i-1];
    }

    ll ans = 0;
    for (int i = 0; i < total.size(); i++){
        ans += (total[i] * (total[i]-1) * (total[i]-2))/6;
        ans += max(0ll, (total[i] * (total[i] - 1))/2 * prefix[i]);
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