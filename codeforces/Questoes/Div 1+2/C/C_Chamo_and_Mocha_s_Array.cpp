#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if (n <= 2){
        cout << min(arr[0], arr[1]) << "\n";
        return;
    }

    int ans = 0;
    for (int i = 2; i < n; i++){
        vector<int> aux = {arr[i-2], arr[i-1], arr[i]};
        sort(aux.begin(), aux.end());
        ans = max(ans, aux[1]); 
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