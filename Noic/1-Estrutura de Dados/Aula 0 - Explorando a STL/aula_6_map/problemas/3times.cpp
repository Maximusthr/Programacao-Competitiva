#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd, times; cin >> qtd >> times;

    map<int, string> nomes;

    int x = qtd;
    while(x--){
        string aux;
        int hab;
        cin >> aux >> hab;
        nomes[hab] = aux;
    }

    vector<set<string>> name(times);

    int y = 0;
    for (auto it = nomes.begin(); it != nomes.end(); it++){
        name[y%times].insert((*it).second);
        y++;
    }


    for (int i = 0; i < times; i++){
        cout << "Time " << i+1 << "\n";
        for (auto nome : name[i]){
            cout << nome << "\n";
        }
        cout << "\n";
    }
}
