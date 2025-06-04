#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);

    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int> ());

    int ans = 0;
    for (int i = 1; i < n; i++){
        ans += abs(arr[i] - arr[0]);
    }

    cout << ans << "\n";
}