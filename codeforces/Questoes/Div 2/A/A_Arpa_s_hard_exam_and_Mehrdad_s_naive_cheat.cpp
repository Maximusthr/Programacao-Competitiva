#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // 8 * 8 = 64
    // 64 * 8 = xx2
    // xx2 * 8 = xx6
    // xx6 * 8 = xx8
    int x; cin >> x;
    
    if (x == 0) cout << 1;
    else if (x % 8 == 0 || x % 8 == 4) cout << 6;
    else if (x % 8 == 1 || x % 8 == 5) cout << 8;
    else if (x % 8 == 2 || x % 8 == 6) cout << 4;
    else if (x % 8 == 3 || x % 8 == 7) cout << 2;
    cout << "\n";
}
