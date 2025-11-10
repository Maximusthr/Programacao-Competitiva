#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    k--;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;
    int pos = -1;
    int talvez = 0;
    for (int i = 0; i < n; i++){
        if (i == k) continue;

        if (k > i && arr[k] < arr[i]) {
            if (i - 1 >= 0) talvez++;

            ans--;
            pos = i;
            break;
        }
        else if (arr[k] > arr[i]){
            ans++;
        }
        else break;
    }

    if (pos != -1){
        for (int i = pos + 1; i < k; i++){
            if (arr[k] > arr[i]) talvez++;
            else break;
        }
    }

    ans = max(ans, talvez);

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}