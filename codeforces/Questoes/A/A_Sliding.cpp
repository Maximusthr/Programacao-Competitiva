#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        ll n, m, r, c; cin >> n >> m >> r >> c;

        ll dist = (n*m) - ((r-1) * m + c) - (n-r) + (n-r)*m;
        
        cout << dist << "\n";
    }
}
