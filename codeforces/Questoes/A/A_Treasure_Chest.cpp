#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int x, y, k; cin >> x >> y >> k;

        if (x >= y) cout << x << "\n";
        else {
            if (y-x <= k) cout << y << "\n";
            else cout << y + y - x - k << "\n";
        }
    }
}
