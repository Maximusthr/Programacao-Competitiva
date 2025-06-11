#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> num(qtd);

    for (auto &i : num) cin >> i;
    sort(num.begin(), num.end());

    for (int i = 0; i < qtd; i++){
        if (i == qtd-1) cout << num[i] << "\n";
        else cout << num[i] << " ";
    }
}
