#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int x, y, z; cin >> x >> y >> z;

        int x1 = abs(y-x) + abs(z-x);
        int y1 = abs(x-y) + abs(z-y);
        int z1 = abs(x-z) + abs(z-y);

        cout << min(x1, min(y1, z1)) << "\n";
    }
}
