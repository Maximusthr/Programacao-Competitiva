#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x, k; cin >> x >> k;
        
        bool ok = false;
        if (x == 1 && k == 2) {
            cout << "YES" << "\n";
            ok = true;
        }
        else if (x == 1 && k == 1){
            cout << "NO" << "\n";
            ok = true;
        } 

        if (!ok) {
            bool primo = true;
            for (int i = 2; i * i <= x; i++){
                if (x % i == 0) {
                    primo = false;
                    break;
                }
            }
            
            if (primo && k == 1) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }

    }
}