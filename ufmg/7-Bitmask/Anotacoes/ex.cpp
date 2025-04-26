#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// É possível formar um subconjunto com 347 moedas?
// Dado v = {130, 222, 147, 99, 101};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    vector<int> v = {130, 222, 147, 99, 101};

    int tam = v.size();

    
    for (int mask = 0; mask < (1 << tam); mask++){
        
        vector<int> val;
        int soma = 0;
        for (int i = 0; i < tam; i++){
            if (mask & (1 << i)) {
                soma += v[i];
                val.push_back(v[i]);
            }
        }
        
        if (soma == 347) {
            for (int i = 0; i < val.size(); i++){
                cout << val[i] << " \n" [i == val.size()-1];
            }
            cout << "YES" << "\n";
        }
    }
}
