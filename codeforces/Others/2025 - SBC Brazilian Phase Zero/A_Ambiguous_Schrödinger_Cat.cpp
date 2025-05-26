#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int x, y; cin >> x >> y;

    if (x == 1) cout << "vivo e morto" << "\n";
    else if (x == 0 && y == 1) cout << "vivo" << "\n";
    else cout << "morto" << "\n";
}