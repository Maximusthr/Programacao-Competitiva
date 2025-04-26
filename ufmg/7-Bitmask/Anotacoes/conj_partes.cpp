#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    // conjunto das partes de um elemento
    vector<int> v = {5, 6, 7};

    int tam = v.size();

    // O(n^2 * n)
    for (int mask = 0; mask < (1 << tam); mask++){
        cout << "{ ";
        for (int bit = 0; bit < tam; bit++){
            if (mask & (1 << bit)) cout << v[bit] << " ";
        }
        cout << "}\n";
    }
}
