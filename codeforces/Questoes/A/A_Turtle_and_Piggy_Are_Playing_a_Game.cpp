#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x, y; cin >> x >> y;

        int l = 1;
        int r = 32;
        int num = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if (pow(2, mid) <= y){
                num = pow(2, mid);
                l = mid+1;
            } 
            else r = mid-1;
        }
        
        int ans = 0;
        while (num > 1){
            ans++;
            num /= 2;
        }

        cout << ans << "\n";
    }
}
