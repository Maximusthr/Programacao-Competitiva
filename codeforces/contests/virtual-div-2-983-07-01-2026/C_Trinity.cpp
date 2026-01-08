#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll ans = LINF;

    for (int i = 2; i <= n; i++){
        ll lim = 0;

        ll sum = arr[i] + arr[i-1];

        ll l = 1, r = n;
        while (l < r){
            ll mid = l + (r-l)/2;

            if (arr[mid] >= sum) r = mid;
            else l = mid + 1;
        }

        if (sum > arr[n]) {}
        else lim += n - l + 1;

        lim += i-2;

        ans = min(lim, ans);
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