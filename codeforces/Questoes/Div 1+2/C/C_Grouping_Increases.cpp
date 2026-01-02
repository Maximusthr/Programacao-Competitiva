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
    int a = INF, b = INF;
    for (int i = 0; i < n; i++){
        if (a > b) swap(a, b);

        if (arr[i] <= a) a = arr[i];
        else if (arr[i] <= b) b = arr[i];
        else {
            a = arr[i];
            ans++;
        }
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