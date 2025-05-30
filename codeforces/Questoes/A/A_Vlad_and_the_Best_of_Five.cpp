#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        string x; cin >> x;

        int cont_A = 0;
        int cont_B = 0;

        for (int i = 0; i < x.size(); i++){
            if (x[i] == 'A') cont_A++;
            else cont_B++;
        }

        if (cont_A > cont_B) cout << "A" << "\n";
        else cout << "B" << "\n";
    }
}