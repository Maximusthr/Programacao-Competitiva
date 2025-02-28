#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int aux; cin >> aux;
        if (aux == 1) cout << "YES" << "\n";
        else if (aux % 3 == 1) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
