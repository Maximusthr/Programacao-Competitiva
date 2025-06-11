#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long x, z; cin >> x >> z;

    if (z-x == 1) cout << "-1" << "\n";
    else {
        // transformar x em divisor de 2 ou 3 em que z tambem seja e x em um numero qualquer
        long long y = 0;
        bool ok = false;

        if (x % 2 != 0 && x % 3 != 0){
            for (long long i = x+1; i <= z-2; i++){
                if (i % 2 == 0 || i % 3 == 0)  {
                    x = i;
                    break;
                }
            }
        }
        if (x % 2 == 0) {
            y = x + 1;
            for (long long i = y+1; i <= z; i++){
                if (i % 2 == 0){
                    z = i;
                    ok = true;
                }
            }
        }
        else if (x % 3 == 0){
            y = x + 1;
            for (long long i = y+1; i <= z; i++){
                if (i % 3 == 0){
                    z = i;
                    ok = true;
                }
            }
        }

        if (y != 0 && (y % 2 == 0 && z % 2 == 0) || (y % 3 == 0 && z % 3 == 0))
        {
            y = z-1;
        }


        if (ok) cout << x << " " << y << " " << z << "\n";
        else cout << "-1" << "\n";
    }
}
