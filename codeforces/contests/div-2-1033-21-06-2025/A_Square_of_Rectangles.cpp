#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (x1 == x2 && x2 == x3){
        if (y1 + y2 + y3 == x1) {
            cout << "YES" << "\n";
            return;
        } 
    }
    if (y1 == y2 && y2 == y3){
        if (x1 + x2 + x3 == y1) {
            cout << "YES" << "\n";
            return;
        }
    }

    if (y1 >= x1){
        if ((y2 + y3 == y1) && (x2 == x3) && (x1 + x2 == y1)){
            cout << "YES" << "\n";
            return;
        }
    }
    if (x1 >= y1){
        if ((x2 + x3 == x1) && (y2 == y3) && (y1 + y2 == x1)){
            cout << "YES" << "\n";
            return;    
        }
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }

}