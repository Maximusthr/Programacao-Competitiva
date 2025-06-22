#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] >= ans) {
            ans++;
        }
    }

    cout << ans << "\n";
}