#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll x; cin >> x;

    if ((x % 10) >= 5){
        ll val = x%10;

        ll a = 10 - val;
    
        x += a;
        
    }
    else {
        ll a = (x%10);
        x -= a;
    }

    cout << x << "\n";
}