#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;
    int um = 0;
    int dois = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0) ans++;
        if (arr[i] == 1) um++;
        if (arr[i] == 2) dois++;
    }

    int x = min(um, dois);
    ans += x;
    um -= x;
    dois -= x;
    ans += um/3;
    ans += dois/3;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}