#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    vector<int> bits(31);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        for (int j = 30; j >= 0; j--){
            if (arr[i] & (1 << j)){
                bits[j]++;
            }
        }
    }

    while (k > 0){
        int aux = k;
        for (int i = 30; i >= 0; i--){
            if (k >= n-bits[i]){
                k -= (n-bits[i]);
                bits[i] = n;
            }
        }
        if (aux == k) break;
    }

    int ans = 0;
    for (int i = 30; i >= 0; i--){
        if (bits[i] == n){
            ans += (1 << i);
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