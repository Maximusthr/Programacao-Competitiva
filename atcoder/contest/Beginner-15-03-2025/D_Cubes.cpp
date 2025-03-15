#include <bits/stdc++.h>

using namespace std;

// got WA 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    long long a; cin >> a;

    // eq segundo grau
    double teste = sqrt(3-(4*3)*(-a+1));
    long long delta = ceil(sqrt(3-(4*3)*(-a+1)));
    long long y = (-3 + delta)/(2*3);

    long long x = y+1;

    //cout << teste << "\n";

    if (x == 0 || y == 0) cout << -1 << "\n";
    else cout << x << " " << y << "\n";
    
    cout << x * x * x - y * y * y << "\n";
}
