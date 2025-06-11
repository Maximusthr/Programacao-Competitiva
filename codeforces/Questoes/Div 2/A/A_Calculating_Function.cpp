#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long x; cin >> x;
    long long par = 0;
    long long impar = 0;
    long long soma_par = 0;
    long long soma_impar = 0;

    if (x % 2 == 0){
       par = x/2;
       impar = x/2;
    }
    else {
        par = x/2;
        impar = x/2+1;
    }
    soma_par = (par + 1) * par;
    soma_impar = (((impar - 1) * impar) + impar) * -1;

    cout << soma_par + soma_impar << "\n";
}