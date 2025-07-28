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

    int q; cin >> q;
    while(q--){
        int x; cin >> x;

        int l = 0, r = n-1;
        while (l < r){
            int mid = l + (r-l+1)/2;

            if (x >= arr[mid]){
                l = mid;
            }
            else r = mid-1;
        }

        cout << (x >= arr[l] ? l+1 : 0) << "\n";
    }

}