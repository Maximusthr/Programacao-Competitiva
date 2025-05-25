#include <bits/stdc++.h>

// WA - only works until 10^10

using namespace std;
using ll = long long;

ll oper (ll a, ll b){
    return pow(2, a) * pow(b, 2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    ll x; cin >> x;

    ll a = 1, b = 1;
    set<ll> verif;

    while(true){
        while(oper(a, b) <= x){
            verif.insert(oper(a,b));
            a++;
            if (a == b) a++;
        }
        a = 1;
        b++;
        if (b == 2) b++;
        if (oper(a, b) > x) break;
    }

    cout << verif.size() << "\n";
}
