#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    vector<int> freq(n);
    int rep = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
        freq[arr[i]]++;
        if (freq[arr[i]] > 1) rep++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (rep == 0) break;
        if (freq[arr[i]] > 1) {
            rep--;
            freq[arr[i]]--;
        }
        ans++;
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
