#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] == arr[i-1] || 7-arr[i] == arr[i-1]){
            // valor que satisfaça arr[i] e arr[i+1]
            set<int> nao_pode = {arr[i], 7-arr[i]};
            if (i+1 != n){
                nao_pode.insert(arr[i+1]);
                nao_pode.insert(7-arr[i+1]);
            }
            for (int j = 1; j <= 6; j++){
                if (!nao_pode.count(j)){
                    arr[i] = i;
                    break;
                }
            }
            ans++;
            i++;
        }
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