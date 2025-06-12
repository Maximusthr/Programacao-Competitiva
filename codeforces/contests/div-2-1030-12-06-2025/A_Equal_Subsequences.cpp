#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        string s;

        bool ok = false;
        int aux = 0;
        for (int i = 0; i < n; i++){
            if (aux == k){
                ok = true;
            }
            if (!ok){
                s += '1';
            }
            else if (ok) {
                s += '0';
            }
            aux++;
        }
        
        cout << s << "\n";
    }
}