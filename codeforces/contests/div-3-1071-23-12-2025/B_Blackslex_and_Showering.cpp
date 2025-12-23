#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    int maior = 0;
    for (auto &i : arr) {
        cin >> i;
    }

    int ans = 0;
    for (int i = 0; i < n-1; i++){
        ans += abs(arr[i] - arr[i+1]);
    }

    int aux = ans;
    for (int i = 0; i < n; i++){
        if (i == 0){
            int v = abs(arr[i] - arr[i+1]);
            aux -= v;
            ans = min(ans, aux);
            aux += v;
        }
        else if (i+1 == n){
            int v = abs(arr[n-2] - arr[n-1]);
            aux -= v;
            ans = min(ans, aux);
            aux += v;
        }
        else {
            int v = abs(arr[i] - arr[i+1]) + abs(arr[i-1] - arr[i]) - abs(arr[i-1] - arr[i+1]);
            aux -= v;
            ans = min(ans, aux);
            aux += v;
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