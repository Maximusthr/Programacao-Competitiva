#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> arr(qtd);

    for (int &i : arr) cin >> i;

    int aux = 1;
    bool ok = false;

    for (int i = 1; i < (int)arr.size(); i++){
        if (arr[i] == arr[i-1]){
            aux++;
            if (aux == 3) {
                ok = true;
                break;
            }
        }
        else aux = 1;

    }

    if (ok) cout << "Yes";
    else cout << "No";
    cout << "\n";
}
