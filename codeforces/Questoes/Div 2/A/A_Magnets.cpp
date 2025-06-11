#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;

    char a, b; cin >> a >> b;
    char temp_a = a, temp_b = b;

    int sum = 1;
    for (int i = 1; i < qtd; i++){
        char aux1, aux2; cin >> aux1 >> aux2;
        if (temp_a != aux1 && temp_b != aux2) {
            sum++;
            temp_a = aux1;
            temp_b = aux2;
        }
    }

    cout << sum << "\n";
}
