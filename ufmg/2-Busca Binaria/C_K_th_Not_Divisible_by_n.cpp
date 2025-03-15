#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        int ans = 0;

        int l = 1;
        int r = 2e9+1;
        while (l <= r){
            int mid = l + (r-l)/2;

            if (mid - (mid/n) >= k){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;

        }
       
        cout << ans << "\n";
    }
}
