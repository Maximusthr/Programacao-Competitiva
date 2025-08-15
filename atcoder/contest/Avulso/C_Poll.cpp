#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    map<string, int> nomes;
    
    int maior = 0;
    for (int i = 0; i < n; i++){
        string s; cin >> s;

        nomes[s]++;
        maior = max(maior, nomes[s]);
    }

    for (auto &[x, y] : nomes){
        if (y == maior) cout << x << "\n";
    }
}