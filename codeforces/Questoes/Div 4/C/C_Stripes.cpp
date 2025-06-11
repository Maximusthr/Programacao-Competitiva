#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){

        vector<string> m(8);
        
        for (int i = 0; i < 8; i++){
            cin >> m[i];
        }

        bool ok = true;
        for (int i = 0; i < 8; i++){
            ok = true;

            for (int j = 0; j < 8; j++){
                if (m[i][j] == '.' || m[i][j] == 'B'){
                    ok = false;
                    break;
                }
            }
            if (ok) break;
        }

        if (ok) cout << "R" << "\n";
        else cout << "B" << "\n";

    }
}