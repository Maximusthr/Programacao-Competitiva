#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        freq[x % k]++;
    }

    int ans = 0;
    for (auto [x, y] : freq){
        if (x == 0) ans += (y%2 ? y-1 : y);
        else ans += min(y, freq[k-x]);
    }

    cout << (ans % 2 == 0 ? ans : ans - 1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}