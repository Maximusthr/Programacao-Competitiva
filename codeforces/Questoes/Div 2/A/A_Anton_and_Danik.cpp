#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;
    string x; cin >> x;

    int a = 0, d = 0;

    for (int i = 0; i < (int)x.size(); i++){
        if (x[i] == 'A') a++;
        if (x[i] == 'D') d++;
    }

    if (a > d) cout << "Anton";
    else if (a < d) cout << "Danik";
    else cout << "Friendship";

    cout << "\n";
}
