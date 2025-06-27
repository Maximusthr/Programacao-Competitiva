#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int i = 1, j = n;
    int sum_left = arr[i], sum_right = arr[j];
    int ans = 0;
    int comeu_left = 1, comeu_right = 1;
    while(i < j){
        if (sum_left == sum_right){
            ans = max(ans, comeu_left + comeu_right);
            i++;
            sum_left += arr[i];
            comeu_left++;
        }
        else if (sum_left < sum_right){
            i++;
            sum_left += arr[i];
            comeu_left++;
        }
        else if (sum_left > sum_right){
            j--;
            sum_right += arr[j];
            comeu_right++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        solve();
    }
}