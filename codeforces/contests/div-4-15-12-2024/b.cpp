#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    while(qtd--){
        string x; cin >> x;

        for (int i = (int)x.size(); i >= 0; i--){
            if (x[i] == 'p') cout << "q";
            if (x[i] == 'q') cout << "p";
            if (x[i] == 'w') cout << "w";
        }
        cout << "\n";
    }
}
