#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n = 3;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int a = arr[0], b = arr[1], c = arr[2];

    if (a == b || b == c){
        cout << 0 << "\n";
        return;
    }

    int ans = 0;
    while(a != b || b != c){
        c--;
        a++;
        ans++;
        if (a == b || b == c) break;
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