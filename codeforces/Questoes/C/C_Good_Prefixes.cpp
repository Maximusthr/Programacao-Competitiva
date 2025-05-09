#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<ll> arr(n);
        for (auto &i : arr) cin >> i;

        ll ans = 0;
        ll sum = 0;
        ll maior = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            maior = max(maior, arr[i]);
            sum -= maior;
            if (sum == maior) ans++;
            sum += maior;
        }

        cout << ans << "\n";
    }
}
