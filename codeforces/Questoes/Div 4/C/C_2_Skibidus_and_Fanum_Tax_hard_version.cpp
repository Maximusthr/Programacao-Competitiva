#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int a, b; cin >> a >> b;
        
        vector<long long> vet(a);
        for (auto &i : vet) cin >> i;
        
        vector<long long> seg(b);
        for (auto &i: seg) cin >> i;
        sort(seg.begin(), seg.end());

        vet[0] = min(vet[0], seg[0] - vet[0]);

        bool ok = true;
        for (int i = 1; i < a; i++){
            auto buscab = upper_bound(seg.begin(), seg.end(), vet[i]);

            long long valor = (buscab == seg.end() ? seg[seg.size()-1] : *buscab);

            vet[i] = min(vet[i], valor - vet[i]);

            if (vet[i] < vet[i-1]) vet[i] = valor - vet[i];
            if (vet[i] < vet[i-1]) {
                cout << "NO" << "\n";
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES" << "\n";
    }
}
