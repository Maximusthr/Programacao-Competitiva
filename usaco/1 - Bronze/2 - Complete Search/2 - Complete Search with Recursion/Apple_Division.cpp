#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll total = accumulate(arr.begin(), arr.end(), 0LL);
    ll ans = LINF;

    for (int i = 0; i < (1 << n); i++){
        ll sum = 0;
        ll temp = total;
        for (int j = 0; j < n; j++){
            if (i & (1 << j)){
                sum += arr[j];
                temp -= sum;
                ans = min(ans, abs(temp-sum));
            }
            temp = total;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    solve();
}