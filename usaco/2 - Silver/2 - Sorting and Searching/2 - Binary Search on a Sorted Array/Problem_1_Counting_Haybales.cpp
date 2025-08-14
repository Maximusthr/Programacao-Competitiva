#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    auto atMost = [&](int x) {
        int l = 0, r = n-1;

        int ans = -1;
        while (l <= r){
            int m = l + (r-l)/2;

            if (arr[m] <= x){
                ans = m;
                l = m + 1;
            }
            else r = m - 1;
        }

        return ans;
    };

    while(q--){
        int x, y; cin >> x >> y;

        cout << atMost(y) - atMost(x-1) << "\n";
    }

    // while(q--){
    //     int x, y; cin >> x >> y;

    //     int ans_x = -1;

    //     int l = 0, r = n-1;
    //     while(l <= r){
    //         int mid = l + (r-l)/2;
    //         if (arr[mid] <= x-1){
    //             l = mid + 1 ;
    //             ans_x = mid;
    //         }
    //         else {
    //             r = mid - 1;
    //         }
    //     }
    //     int ans_y = -1;
    //     l = 0, r = n-1;
    //     while(l <= r){
    //         int mid = l + (r-l)/2;

    //         if (arr[mid] <= y){
    //             l = mid+1;
    //             ans_y = mid;
    //         }
    //         else r = mid - 1;
    //     }

    //     cout << ans_y - ans_x << "\n";
    // }
}