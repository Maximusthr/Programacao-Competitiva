#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int i = 0, j = 0;
    int sum = 0;
    int ans = 0;
    while (i < n || j < n){
        if (sum > k || j >= n){
            sum -= arr[i];
            i++;
            if (sum <= k) ans = max(ans, sum);
        }
        else {
            if (j < n) {
                sum += arr[j];
                j++;
            }
            
            if (sum <= k) ans = max(ans, sum);
            if (ans == k) break;
        }
    }

    cout << ans << "\n";
}
