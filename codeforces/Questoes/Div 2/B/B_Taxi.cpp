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

    sort(arr.begin(), arr.end());

    int ans = 0, da = 0;
    int l = 0, r = n-1;
    while(l <= r){
        while(r >= l && arr[r] + arr[l] > 4){
            ans++;
            r--;
        }
        if (r < 0 || l > r) break;

        int can = arr[l];
        while(l < n && arr[r] + can <= 4){
            l++;
            can += arr[l];
        }
        ans++;
        r--;
        can = 0;
    }

    cout << ans << "\n";
}
