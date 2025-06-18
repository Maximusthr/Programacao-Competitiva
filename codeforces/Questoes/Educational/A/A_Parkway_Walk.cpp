#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        int sum = accumulate(arr.begin(), arr.end(), 0);

        if (m >= sum) cout << 0 << "\n";
        else cout << sum - m << "\n";
    }
}
