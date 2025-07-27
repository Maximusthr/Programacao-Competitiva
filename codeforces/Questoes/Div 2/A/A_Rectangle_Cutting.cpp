#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y; cin >> x >> y;

    if (x >= 2 && y >= 2 && (x%2 == 0 && y%2 == 0)){
        cout << "YES" << "\n";
        return;
    }

    if ((x%2 && y%2)){
        cout << "NO" << "\n";
        return;
    }

    int temp_x = x, temp_y = y;

    if (x % 2 && y % 2 == 0){
        temp_x += y/2;
        temp_y /= 2;

        if (temp_x == y && temp_y == x) {
            cout << "NO" << "\n";
            return;
        }
    }
    else if (x % 2 == 0 & y % 2){
        temp_y += x/2;
        temp_x /= 2;

        if(temp_x == y && temp_y == x){
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";

    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}