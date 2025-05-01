#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        string x; cin >> x;
        
        bool ok = true;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (x[i] == x[j]){
                    if ((j - i) % 2) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) break;
        }

        if (ok) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
