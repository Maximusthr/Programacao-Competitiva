#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0, j = n - 1; i <= j;){
        if (arr[i] + arr[j] <= k) {
            ans++;
            i++, j--;
        }
        else {
            j--;
            ans++;
        }
    }

    cout << ans << "\n";
}