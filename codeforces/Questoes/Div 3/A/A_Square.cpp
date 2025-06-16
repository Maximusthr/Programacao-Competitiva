#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int a, b, c, d, e, f, g, h;
        cin >> a >> b;
        cin >> c >> d;
        cin >> e >> f;
        cin >> g >> h;

        cout << (max({a, c, e, g}) - min({a, c, e, g})) * (max({b, d, f, h}) - min({b, d, f, h})) << "\n";
    }
}