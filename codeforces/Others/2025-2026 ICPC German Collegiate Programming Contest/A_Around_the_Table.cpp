// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll l, r; cin >> l >> r;

    
    if (r == l - 1){
        cout << l + r << "\n";
    }
    else if (r == l || r == l - 2){
        cout << l + r + (l + r)/2 << "\n";
    }
    else{
        cout << 2 * (l + r) << "\n";
    }
}