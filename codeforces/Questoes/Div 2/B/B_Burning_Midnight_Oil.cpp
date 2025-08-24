#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll exp(ll a, ll b){
    ll x = 1;

    while(b > 0){
        if (b % 2) x *= a;
        a *= a;
        b >>= 1;
    }

    return x;
}

ll n, k;

bool ok(ll mid){

    ll valor = mid;
    ll aux = 0;

    ll total = 0;

    while (valor/(exp(k, aux)) > 0){
        total += valor/(exp(k, aux));
        aux++;
    }

    return (total >= n);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> k;

    ll l = 0, r = 1e15;
    while(l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << l << "\n";
}