#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;

    vector<int> arr(qtd);
    for (int &i : arr) cin >> i;

    int sum = 0;
    for (int i = 0; i < qtd; i++) sum += arr[i]/2;

    vector<int> pos(qtd, 0);
    int aux = 0;
    for (int i = 0; i < qtd; i++){
        if (arr[i] % 2 != 0){
            aux = arr[i]; // fix the case -> x = -1 || x = 1
            arr[i] /= 2;
            pos[i] = 1;
            if (sum < 0 && aux > 0){
                arr[i]++;
                sum++;
            }
            else if (sum > 0 && aux < 0) {
                arr[i]--;
                sum--;
            }
        }
    }

    for (int i = 0; i < qtd; i++){
        if (arr[i] % 2 == 0 && pos[i] != 1){
            arr[i] /= 2;
        }
    }

    for (int i = 0; i < qtd; i++){
        cout << arr[i] << "\n";
    }

}
