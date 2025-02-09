#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int m; cin >> m;

    int ans = 0;
    int aux = 0;

    if (n % 3 == 1){
        ans = 1;
    } else if (n % 3 == 2){
        ans = 2;
    } else {
        ans = 0;
    }
    
    if (m % 3 == 1){
        aux = 1;
        if (aux == ans) aux++; // aux = 2
    } else if (m % 3 == 2){
        aux = 2;
        if (aux == ans) aux = 0; // aux = 0
    } else {
        aux = 0;
        if (aux == ans) aux++; // aux = 1.
    }

    int soma = ans + aux;

    int result = 0;

    if (soma == 1){ // 0 + 1, resta 2
        result = 2;
    } else if (soma == 2){ // 0 + 2, resta 1
        result = 1;
    } else if (soma == 3){ // 1 + 2, resta 0
        result = 0;
    }

    cout << result << "\n";
}