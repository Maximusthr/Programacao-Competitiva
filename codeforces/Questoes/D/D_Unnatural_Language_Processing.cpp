#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int qtd; cin >> qtd;

        string word;
        cin >> word;

        string aux;
        aux += word[0];
        for (int i = 1; i < qtd; i++){
            if ((word[i] == 'b' || word[i] == 'c' || word[i] == 'd') && (word[i-1] == 'a' || word[i-1] == 'e')){
                if (i != qtd-1) {
                    if (word[i+1] == 'a' || word[i+1] == 'e'){
                        aux += '.';
                        aux += word[i];
                    }
                    else {
                        aux += word[i];
                        aux += '.';
                    }
                }
                else aux += word[i];
            } 
            else aux += word[i];
        }

        cout << aux << "\n";
    }
}