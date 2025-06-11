#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    int soma = 0;

    while (n--){
        int p, q; cin >> p >> q;
        if (q-p >= 2) soma++;
    } 

    cout << soma << "\n";
}
