#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    
    vector<int> arr(n+k+5);
    vector<int> minut(n+k+5);

    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) cin >> minut[i];

    vector<int> prefix(n+k+5);
    vector<int> total(n+k+5);

    for (int i = 1; i <= n+k+2; i++) {
        prefix[i] += prefix[i-1] + (minut[i] ? arr[i] : 0);
        total[i] += total[i-1] + arr[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(prefix[n+k+1] - prefix[i+k-1] + prefix[i-1] + total[i+k-1] - total[i-1], ans);
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}