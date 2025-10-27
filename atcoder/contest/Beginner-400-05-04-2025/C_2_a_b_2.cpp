#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll n; cin >> n;

    ll a1 = sqrtl(n/2);
    ll a2 = sqrtl(n/4);

    cout << a1+a2 << "\n";
}