#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k, x; cin >> n >> k >> x;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int sum = accumulate(arr.begin(), arr.end(), 0);
    for (int i = n-1; i >= n-x; i--){
        sum -= (arr[i] * 2);
    }
    
    int j = n-x;
    int ans = sum;
    for (int i = n-1; i >= 0; i--){
        if (k > 0){
            sum += arr[i];
            k--;
            j--;
            if (j >= 0) sum -= 2 * arr[j];
        }
        ans = max(ans, sum);
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