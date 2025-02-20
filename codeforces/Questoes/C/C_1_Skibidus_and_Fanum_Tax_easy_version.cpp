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

        for (int i = 0; i < a; i++){
            if (i == a-1) {
                if (a > 1 && m - vet[i] >= vet[i-1]) vet[i] = m-vet[i];
            }
            else if (i < a - 1 && m - vet[i] <= vet[i+1]) vet[i] = m - vet[i];
        }

        cout << (is_sorted(vet.begin(), vet.end()) ? "YES" : "NO") << "\n";
    }
}
