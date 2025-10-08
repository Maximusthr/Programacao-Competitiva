#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> b(k);
    for (auto &i : b) cin >> i;

    vector<int> prefix(k+1, INF);
    prefix[0] = 0;
    for (int i = 0, j = 0; i < k; i++){
        while (j < n && a[j] < b[i]) j++;
        if (j >= n) break;
        prefix[i+1] = ++j;
    }

    vector<int> suffix(k+1, -1);
    suffix[k] = n;
    for (int i = k-1, j = n-1; i >= 0; i--){
        while(j >= 0 && a[j] < b[i]) j--;
        if (j < 0) break;
        suffix[i] = j--;
    }

    if (prefix[k] <= n) {
        cout << 0 << "\n";
        return;
    } 

    int ans = INF;
    for (int i = 0; i < k; i++){
        if (prefix[i] <= suffix[i+1]){
            ans = min(ans, b[i]);
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}