#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    vector<int> perm(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        perm[arr[i]] = i;
    }

    int ans = 0, aux = 0;
    vector<bool> mark(n+1);
    for (int i = 1; i <= n; i++){
        if (!mark[i]) {
            aux++;
            mark[arr[i]] = true;
        }
        else {
            // aux--;
            mark[arr[i]] = true;
        }
        ans = max(ans, aux);
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