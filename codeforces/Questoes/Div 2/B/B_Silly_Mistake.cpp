#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;

void solve(){
    int n; cin >> n;

    vector<int> aux(MAX, -1);
    map<int, int> pos;
    map<int, int> neg;

    set<int> d;

    vector<int> days;
    int sum = 0;
    
    int trocou = 0;

    for (int i = 0; i < n; i++){
        int x; cin >> x;

        if (x > 0){
            if (pos[x] > neg[-x]) {
                cout << -1 << "\n";
                return;
            }

            // se por acaso "trocou" o dia
            // eu sei se eu nao estou visitando aquele dia novamente
            if (aux[x] == trocou){
                cout << -1 << "\n";
                return;
            }

            pos[x]++;
            d.insert(x);
            sum++;
            aux[x] = trocou;
        }
        else {
            if (neg[x] >= pos[-x]){
                cout << -1 << "\n";
                return;
            }

            neg[x]++;
            d.erase(-x);
            sum++;
            if (d.empty()){
                days.push_back(sum);
                sum = 0;
                trocou++;
            }
        }
    }

    if (!d.empty()){
        cout << -1 << "\n";
        return;
    }

    cout << days.size() << "\n";
    for (auto &i : days) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}