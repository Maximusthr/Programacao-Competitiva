#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        ll n; cin >> n;

        if (n % 2 || n < 4) cout << -1 << "\n";
        else cout << n/6 + (n%6 > 0) << " " << n/4 << "\n";
    }
}
