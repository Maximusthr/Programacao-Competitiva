#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    while(q--){
        int x; cin >> x;

        int l = 0, r = n-1;
        while (l < r){
            int mid = l + (r-l)/2;

            if (arr[mid] < x){
                l = mid + 1;
            }
            else r = mid;
        }
        if (arr[l] == x) cout << l << "\n";
        else cout << -1 << "\n";
    }
}