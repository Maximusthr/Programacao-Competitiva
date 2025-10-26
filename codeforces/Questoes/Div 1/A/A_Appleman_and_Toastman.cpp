#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (n == 1){
        cout << arr[0] << "\n";
        return 0;
    }

    sort(arr.begin(), arr.end());

    ll ans = 0;
    int rep = 2;
    for (int i = 0; i < n; i++){
        if (i == n-1) rep--;
        ans += 1ll * arr[i] * rep;
        rep++;
    }

    cout << ans << "\n";
}