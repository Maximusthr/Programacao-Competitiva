#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x; cin >> x;

    if (x <= 5) cout << 1 << "\n";
    else {
        if (x % 5 == 0) cout << x/5 << "\n";
        else cout << (x/5) + 1 << "\n";
    }
}
