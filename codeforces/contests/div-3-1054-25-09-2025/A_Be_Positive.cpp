#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    int ans = 0;
    int neg = 0;
    int zero = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] < 0) neg++;
        else if (arr[i] == 0) zero++;
    }

    if (neg % 2) ans += 2;
    ans += zero;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}