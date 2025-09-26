#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, x, y; cin >> n >> x >> y;

    ll cm = (x * y)/(__gcd(x, y));

    ll rep = n/cm;

    ll nx = (n/x) - rep;
    ll ny = (n/y) - rep;

    ll mx_sum = (nx)*(2*n-nx+1)/2;
    ll min_sum = ny*(ny+1)/2;

    cout << mx_sum - min_sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}