#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x; cin >> x;
    
    if (400 % x != 0) cout << -1 << "\n";
    else cout << 400/x << "\n";
}