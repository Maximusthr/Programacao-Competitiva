#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int x, d; cin >> x >> d;

    if (x >= 1600 && x <= 2999 && d == 1) cout << "Yes" << "\n";
    else if (x >= 1200 && x <= 2399 && d == 2) cout << "Yes" << "\n";
    else cout << "No" << "\n";

}