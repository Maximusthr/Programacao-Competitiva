#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int x = 33;
    
    // representação do numero em binario
    bool ok = false;
    for (int i = 30; i >= 0; i--){
        if ((x & (1 << i))) {
            ok = true;
            cout << 1;
        }
        else if (ok) cout << 0;
    }
    cout << "\n";
}
