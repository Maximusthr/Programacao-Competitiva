#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll B, P, M;

ll power(ll B, ll P){
    if (P == 0) return 1 % M;
    if (P == 1) return B % M;

    ll temp = power(B % M, P/2);
    if (P % 2 == 0) return temp * temp % M;
    else return B * temp * temp % M;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    while(cin >> B >> P >> M){   
        cout << power(B % M, P) << "\n";
    }
}
