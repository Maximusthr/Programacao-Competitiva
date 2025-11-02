#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    auto ok = [&](ll mid) -> bool {
        int box = 1;
        ll sum = 0;
        int count = 0;
        for (int i = n-1, j = 0; i >= j; i--){
            if (arr[i] > mid) return false;

            sum += arr[i];
            count++;

            if (count == 3){
                box++;
                sum = arr[i];
                count = 1;
            }
            else if (sum > mid){
                sum -= arr[i];
                if (sum + arr[j] > mid){
                    box++;
                    sum = arr[i];
                    count = 1;
                }
                else {
                    sum += arr[j];
                    j++;
                    i++;
                }
            }
        }

        return (box <= k);
    };

    ll l = 0, r = 1e9;
    while (l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << l << "\n";
}