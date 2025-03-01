#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd;

    cin >> qtd;

    vector<int> arr(qtd);
    for (auto &i : arr) cin >> i;

    bool ok = true;
    for (int i = 1; i < qtd; i++){
        if (arr[i] <= arr[i-1]) {
            ok = false;
            break;
        }
    }

    if (ok) cout << "Yes";
    else cout << "No";
    cout << "\n";
}
