#include <bits/stdc++.h>

using namespace std;

void Fatorando(int x){
    while (x % 2 == 0) {
        cout << 2 << "\n";
        x /= 2;
    }

    for (int i = 3; i*i <= x; i += 2){
        while (x % i == 0){
            cout << i << "\n";
            x /= i;
        }
        if (x != 1) cout << i << "\n";
    }
}

// gcd outra forma:

// int gcd(int a, int b){
//     if (b == 0) return a;
//     return gcd(b, a%b);
// }


int main(){
    int x; cin >> x;

    Fatorando(x);
    return 0;
}
