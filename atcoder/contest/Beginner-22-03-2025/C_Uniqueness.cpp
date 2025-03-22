#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;

    map<int, int> arr;
    vector<pair<int, int>> pos;

    for (int i = 0; i < qtd; i++){
        int aux; cin >> aux;
        arr[aux]++;
        pos.push_back({aux, i});
    }

    int maior = 0;
    vector<pair<int, int>> val;
    for (int i = 0; i < qtd; i++){
        if (arr[pos[i].first] == 1) 
            maior = max(maior, pos[i].first);
            if (pos[i].first == maior) val.push_back({pos[i].first, pos[i].second});
    }

    if ((int)val.size() >= 1) cout << val[(int)val.size()-1].second + 1 << "\n";
    else cout << "-1" << "\n";  
}
