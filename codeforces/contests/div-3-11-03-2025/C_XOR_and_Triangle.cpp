#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){;
        long long x; cin >> x;
        long long y = 0;

        bool ok = false;
        for (int i = x-1; i >= x - 100000 && i > 0; i--){
            y = i;
            long long aux = (x ^ y);

            if (x + aux > y && x + y > aux && y + aux > x){
                ok = true;
                break;
            }
        }

        if (!ok) cout << -1 << "\n";
        else cout << y << "\n";
    }
}