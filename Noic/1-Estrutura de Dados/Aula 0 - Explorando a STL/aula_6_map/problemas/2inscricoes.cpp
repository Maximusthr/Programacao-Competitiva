#include <bits/stdc++.h>

using namespace std;

int main(){
    map<string, int> times;
    vector<string> aux;

    int x;
    while(cin >> x && x){
        for (int i = 0; i < x; i++){
            string aux1, aux2; cin >> aux1 >> aux2;
            times[aux2]++;
            if (times[aux2] == 1) aux.push_back(aux2);
        }
    }

    for (int i = 0; i < (int)aux.size(); i++){
        cout << aux[i] << " " << times[aux[i]] << "\n";
    }
}
