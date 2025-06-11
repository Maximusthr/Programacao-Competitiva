#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    long long ans = 0;
    while(t--){
        string x; cin >> x;

        if (x == "Icosahedron") ans += 20;
        else if (x == "Cube") ans += 6;
        else if (x == "Tetrahedron") ans += 4;
        else if (x == "Dodecahedron") ans += 12;
        else if (x == "Octahedron") ans += 8;
    }

    cout << ans << "\n";
}
