#include <bits/stdc++.h>

using namespace std;

bool isPrime(int y){
    for (int i = 2; i <= sqrt(y); i++){
        if (y % i == 0) return false;
    }
    return true;
}

int main(){
    int x, y; cin >> x >> y;

    bool ok = isPrime(y);

    if (!ok) cout << "NO" << "\n";
    else {
        for (int i = x+1; i < y; i++){
            if (isPrime(i)) {
                ok = false;
                cout << "NO" << "\n";
                break;
            }
        }
        if (ok) cout << "YES"<< "\n";
    }
}
