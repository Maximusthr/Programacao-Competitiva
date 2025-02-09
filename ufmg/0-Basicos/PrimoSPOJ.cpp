#include <bits/stdc++.h>

using namespace std;

int main(){
    int x; cin >> x;
    
    bool ok = true;
    if (x == 1) ok = false;
    else {
        for (int i = 2; i <= sqrt(x); i++){
            if (x % i == 0) ok = false;
        }
    }

    cout << (ok ? "sim" : "nao") << "\n";
}
