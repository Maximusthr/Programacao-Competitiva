#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<set<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    
    vector<int> seq(n);
    for (auto &i : seq) {
        cin >> i;
        i--;
    }

    if (seq[0] != 0){
        cout << "No" << "\n";
        return;
    }

    int i = 0;
    int ant = 1;
    while(i < n){
        int atual = seq[i];
        
        int viz = g[atual].size();
        if (i > 0) viz--;

        for (int j = ant; j < ant + viz; j++){
            if (!g[atual].count(seq[j])){
                cout << "No" << "\n";
                return;
            }
        }

        i++;
        ant += viz;
    }

    cout << "Yes" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}