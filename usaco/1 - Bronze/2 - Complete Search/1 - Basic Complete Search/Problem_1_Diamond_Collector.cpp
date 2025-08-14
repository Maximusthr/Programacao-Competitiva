#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < n; i++){
        vector<int> aux;
        aux.push_back(arr[i]);
        for (int j = i+1; j < n; j++){
            if (arr[j] - arr[i] <= k) aux.push_back(arr[j]);
        }

        ans = max(ans, (int)aux.size());
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    solve();
}
