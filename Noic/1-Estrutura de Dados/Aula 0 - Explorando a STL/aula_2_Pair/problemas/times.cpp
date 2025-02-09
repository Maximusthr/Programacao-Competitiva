#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, string>> var;

    int nomes, times; cin >> nomes >> times;

    for (int i = 0; i < nomes; i++){
        string aux; int hab; cin >> aux >> hab;
        var.push_back({hab, aux});
    }

    sort(var.rbegin(), var.rend()); //sort a partir das habilidades;

    for (int i = 0, n = 0; i < times; i++){
        n = i;
        cout << "Time " << i+1 << "\n";
        vector<string> names;
        for (int j = 0; j < nomes; j++){
            if (n >= nomes) {
                sort(names.begin(), names.end());
                for (int k = 0; k < names.size(); k++){
                    cout << names[k] << "\n";
                }
                break;
            }
            names.push_back(var[n].second);
            //cout << var[n].second << "\n";
            n += times;
        }
        cout << "\n";
    }
}
