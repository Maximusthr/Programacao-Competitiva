#include <bits/stdc++.h>

using namespace std;

// got WA

int main(){
    string x; cin >> x;

    int ans = 0;
    int qtd_i = 0;
    int qtd_o = 0;

    for (int i = 0; i < (int)x.size(); i++){
        if (i % 2 == 0 && x[i] != 'i') {
            ans++;
        }
        else if (i % 2 == 1 && x[i] != 'o') {
            ans++;
        }
    }
    if (x.size() % 2 == 1) ans++;
    
    cout << ans << "\n";

}

