#include <bits/stdc++.h>

using namespace std;

// fazer busca binaria na resposta

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){;
        int x; cin >> x;

        bool ok = false;       
        int l = 1;
        int r = x-1;
        int aux = 0;
        int ans = 0;
        while (l <= r){
            int mid = l + (r-l)/2;
            aux = (x ^ mid);
            if (x + aux > mid && x + mid > aux && mid + aux > x){
                ans = mid;
                //r = mid - 1;
                ok = true;
                break;
            }
            else {
                l = mid + 1;
            }
        }
        
        if (!ok) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}
