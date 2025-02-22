#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;
    string x; cin >> x;

    char temp = x[0];

    int sum = 0;
    for (int i = 1; i < (int)x.size(); i++){
        if (x[i] == temp) sum++;
        else temp = x[i];
    }

    cout << sum << "\n";
}
