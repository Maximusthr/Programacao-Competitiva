#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        int ans = 0;

        if (n == k) ans = k + 1;
        else {
            int r = k % (n-1);
            int div = k/(n-1);

            ans = (div * n) + r;
            if (r == 0) ans--;
        }

        cout << ans << "\n";
    }
}
