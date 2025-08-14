#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<string> c = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string, int> cows;

    for (int i = 0; i < (int)c.size(); i++) cows[c[i]] = 0;

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        int qtd; cin >> qtd;
        cows[s] += qtd;
    }
    
    int menor = INF;
    for (auto [x, y] : cows) menor = min(menor, y);

    int seg_menor = INF;
    for (auto [x, y] : cows){
        if (y == menor) continue;
        seg_menor = min(seg_menor, y);
    }

    string name; 
    int qtd = 0;
    for (auto [x, y] : cows){
        if (y == seg_menor){
            name = x;
            qtd++;
        }
    }
    if (qtd != 1) cout << "Tie" << "\n";
    else cout << name << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    solve();
}