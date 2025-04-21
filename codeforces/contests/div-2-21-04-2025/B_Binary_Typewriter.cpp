#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int s; cin >> s;
        string x; cin >> x;

        // se for 1, tento achar até onde tiver 0 e depois 1 e realizo o reverse
        bool ok = false;
        int pos_one = 0;
        for (int i = 0; i < s; i++){
            if (x[i] == '1' && !ok) {
                pos_one = i;
                ok = true;
                continue;
            }
            if (ok){
                if (x[i] == '0' && i+1 == s){
                    reverse(x.begin() + pos_one, x.begin() + i+1);
                    break;
                }
                else if (x[i] == '0' && x[i+1] == '1'){
                    reverse(x.begin() + pos_one, x.begin() + i+1);
                    break;
                }
            }
        }   

        int op = 0;
        for (int i = 0; i < s; i++){
            if (i == 0 && x[i] == '0') op++;
            else if (i == 0 && x[i] == '1') op += 2;
            else if (x[i] != x[i-1]) op +=2;
            else op++;
        }

        cout << op << "\n";
    }
}
