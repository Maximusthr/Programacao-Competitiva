#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<string, int> mapa;
    for (int i = 0; i < n; i++){
        string x; cin >> x;
        
        transform(x.begin(), x.end(), x.begin(), [&](char c){
            return tolower(c);
        });

        mapa[x]++;
    }

    int maior = 0;
    for (auto [x, y] : mapa){
        maior = max(maior, y);
    }

    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
