#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    ll sum = 0;
    
    int i = 0, j = 0;
    while (i < n || j < n){
        if (i > j) j = i;

        if (j == n || sum >= k){
            if (sum == k) ans++;
            sum -= arr[i];
            i++;
        }
        else if (i == n || sum < k){
            sum += arr[j];
            j++;
        }
    }

    cout << ans << "\n";
}
