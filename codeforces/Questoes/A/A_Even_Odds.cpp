#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long x, pos; cin >> x >> pos;

    if (x % 2 == 0){
        if (pos <= x/2) cout << pos + pos-1 << "\n";
        else cout << (pos-(x/2))*2 << "\n";
    }
    else {
        if (pos <= (x/2)+1) cout << pos + pos-1 << "\n";
        else cout << ((pos-(x/2))*2)-2 << "\n";
    }
}
