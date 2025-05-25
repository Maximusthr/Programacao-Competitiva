#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    long long x, y; cin >> x >> y;

    long long soma = 0;

    bool ok = true;
    for (int i = 0; i <= y; i++){
        soma += pow(x, i);
        if (soma >= 1000000001){
            cout << "inf" << "\n";
            ok = false;
            break;
        }
    }

    if (ok) cout << soma << "\n";
}
