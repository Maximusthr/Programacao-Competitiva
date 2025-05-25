#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, m, l, r; cin >> n >> m >> l >> r;

        if (n == m) cout << l << " "  << r << "\n";
        else {
            int oper = n-m;
            
            l += oper;
            if (l > 0){
                int dif = l;
                l = 0;
                r -= dif;
            }

            cout << l << " " << r << "\n";
        }
    }
}
