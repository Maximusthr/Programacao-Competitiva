#include <bits/stdc++.h>

using namespace std;

int main(){
    string x, y;

    while(cin >> x >> y){
        int soma = 0;

        for (int i = 0, j = 0; i < (int)y.size(); i++){
            if (x[j] == y[i]){
                soma++;
                j++;
            }
        }

        if (soma == (int)x.size()) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}
