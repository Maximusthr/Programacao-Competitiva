#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;
    
    while(qtd--){
        string x; cin >> x;

        bool ok = false;
        for (int i = 0; i < (int)x.size()-1; i++){
            if (x[i] == x[i+1]) ok = true;
        }

        if (ok) cout << 1 << "\n";
        else cout << (int)x.size() << "\n";
    }
}
