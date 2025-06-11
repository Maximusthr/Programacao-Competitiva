#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;

        int dif = c - b;
        a += dif;
        if (a < b) cout << "NO" << "\n";
        else {
            int dif2 = a - b;
            if (dif2 % 3 == 0) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}
