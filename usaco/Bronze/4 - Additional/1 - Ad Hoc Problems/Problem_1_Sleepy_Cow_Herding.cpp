#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    vector<int> elem(3);
    for (int &i : elem) cin >> i;
    
    sort(elem.begin(), elem.end());

    if (elem[0] + 1 == elem[1] && elem[1] + 1 == elem[2]){
        cout << 0 << "\n";
        cout << 0 << "\n";
        return;
    }

    // achando o minimo de movimentos
    int menor = 0;
    if (elem[1] - elem[0] == 2 || elem[2] - elem[1] == 2) menor = 1;
    else menor = 2;

    // achando o maximo de movimentos
    int maior = 0;
    if (elem[1] - elem[0] > elem[2] - elem[1]){
        maior = elem[1] - elem[0] - 1;
    }
    else maior = elem[2] - elem[1] - 1;

    cout << menor << "\n";
    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    solve();
}