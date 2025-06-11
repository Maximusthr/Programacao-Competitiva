#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string x; cin >> x;

    int sum = 0;
    for (int i = 0; i < (int)x.size(); i++){
        sum += x[i] - '0';
    }

    int oper = 0;
    if (sum >= 10) oper++;
    else if (x.size() == 1) {
        cout << 0 << "\n";
        return 0;
    }

    int aux = 0;
    while (true){
        if (sum == 0){
            oper++;
            if (aux >= 10) {
                sum = aux;
                aux = 0;
            }
            else break;
        }
        aux += sum % 10;
        sum /= 10;
    }

    cout << oper << "\n";
}
