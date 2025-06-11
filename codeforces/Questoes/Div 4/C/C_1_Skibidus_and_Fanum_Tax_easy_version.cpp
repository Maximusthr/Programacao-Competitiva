#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int a, b; cin >> a >> b;
        
        vector<int> vet(a);
        for (auto &i : vet) cin >> i;
        
        int m; cin >> m;

        vet[0] = min(vet[0], m - vet[0]);

        bool ok = true;
        for (int i = 1; i < a; i++){
            vet[i] = min(vet[i], m - vet[i]);
            if (vet[i] < vet[i-1]) vet[i] = m-vet[i];
            if (vet[i] < vet[i-1]) {
                cout << "NO" << "\n";
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES" << "\n";
    }
}
