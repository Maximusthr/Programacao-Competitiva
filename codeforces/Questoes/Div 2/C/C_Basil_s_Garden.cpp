#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    reverse(arr.begin(), arr.end());

    int ans = arr[0];    
    for (int i = 1; i < n; i++){
        ans = max(ans + 1, arr[i]);
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