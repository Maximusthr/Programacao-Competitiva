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
    sort(arr.begin(), arr.end());

    int i = 0, j = 0;
    int ans = INF;

    while(i < n && j < n){
        while(j < n && arr[i] == arr[j]){
            j++;
        }
        if (i == j) ans = min(ans, max(i, n - j - 1));
        else ans = min(ans, max(i, n - j));
        i = j;
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