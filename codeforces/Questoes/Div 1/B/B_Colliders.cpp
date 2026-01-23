#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;
vector<int> crivo;

void solve(){
    int n, m; cin >> n >> m;
    
    map<int, set<int>> mapa;

    while(m--){
        char c; cin >> c;
        int x; cin >> x;

        set<int> fact;
        int aux = x;
        while(aux > 1){
            fact.insert(crivo[aux]);
            aux /= crivo[aux];
        }
        // fact.insert(1);

        vector<int> fat = {fact.begin(), fact.end()};

        if (x == 1){
            if (c == '+'){
                if (mapa[1].count(1)){
                    cout << "Already on" << "\n";
                }
                else {
                    mapa[1].insert(1);
                    cout << "Success" << "\n";
                }
            }
            else {
                if (!mapa[1].count(1)){
                    cout << "Already off" << "\n";
                }
                else {
                    mapa[1].erase(1);
                    cout << "Success" << "\n";
                }
            }
            continue;
        }

        if (c == '+'){
            if (mapa[fat[0]].count(x)){
                cout << "Already on" << "\n";
                continue;
            }

            bool ok = false;
            for (int i = 0; i < fat.size(); i++){
                if (!mapa[fat[i]].empty()){
                    cout << "Conflict with " << *mapa[fat[i]].begin() << "\n";
                    for (int j = i; j >= 0; j--){
                        mapa[fat[j]].erase(x);
                    }
                    ok = true;
                    break;
                }
                mapa[fat[i]].insert(x);
            }

            if (ok) continue;

            cout << "Success" << "\n";
        }
        else {
            if (!mapa[fat[0]].count(x)){
                cout << "Already off" << "\n";
                continue;
            }

            for (int i = 0; i < fat.size(); i++){
                mapa[fat[i]].erase(x);
            }

            cout << "Success" << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    crivo.resize(MAX);

    crivo[0] = 0;
    crivo[1] = 1;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i] == 0){
            crivo[i] = i;
            for (ll j = i * i; j < MAX; j += i){
                if (crivo[j] == 0){
                    crivo[j] = i;
                }
            }
        }
    }

    solve();
}