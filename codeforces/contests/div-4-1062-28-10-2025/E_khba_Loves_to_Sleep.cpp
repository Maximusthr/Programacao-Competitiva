// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k, dist; cin >> n >> k >> dist;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    auto ok = [&](ll mid) -> bool {
        ll sum = 0;

        // do zero
        for (int i = 0; i <= arr[0] - mid; i++){
            if (sum == k) return true;
            sum++;
        }
        // do meio
        for (int i = 0; i < n-1; i++){
            for (int j = arr[i] + mid; j <= arr[i+1] - mid; j++){
                sum++;
                if (sum == k) return true;
            }
        }
        // de tras
        for (int i = arr[n-1] + mid; i <= dist; i++){
            if (sum == k) return true;
            sum++;
        }

        return (sum >= k);
    };

    ll l = 0, r = 1e9;
    while(l < r){
        int mid = l + (r-l+1)/2;

        if (ok(mid)){
            l = mid;
        }
        else r = mid - 1;
    }
    set<int> pos;

    for (int i = 0; i <= arr[0] - l && pos.size() < k; i++){
        pos.insert(i);
    }
    for (int i = 0; i < n-1 && pos.size() < k; i++){
        for (int j = arr[i] + l; j <= arr[i+1] - l && pos.size() < k; j++){
            pos.insert(j);
        }
    }
    for (int i = arr[n-1] + l; i <= dist && pos.size() < k; i++){
        pos.insert(i);
    }

    for (auto i = pos.begin(); i != pos.end(); i++){
        cout << *i << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}