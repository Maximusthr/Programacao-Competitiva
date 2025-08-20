#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> arr(qtd);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int menor = arr[0];
    int maior = arr[qtd-1];
    int sum = 0;
    for (int i = 0; i < qtd; i++){
        if (arr[i] == menor || arr[i] == maior) continue;
        else sum++;
    }

    cout << sum << "\n";
}
