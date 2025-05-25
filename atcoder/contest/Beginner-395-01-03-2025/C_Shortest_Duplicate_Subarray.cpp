#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;

    vector<int> arr(qtd);
    for (auto &i : arr) cin >> i;

    map<int, int> subarray;

    for (int i = 0; i < qtd; i++){
        subarray[arr[i]]++;
    }

    int sum = 1;
    bool ok = false;
    vector<int> menor_soma;
    for (int i = 0; i < arr.size(); i++){
        if (subarray[arr[i]] >= 2){
            for (int j = i+1; j < arr.size(); j++){
                if (arr[i] == arr[j]) {
                    sum++;
                    ok = true;
                    break;
                }
                sum++;
            }
            if (!ok) {
                // chegou ao final e não capturou nada
                sum = 10000000;
            }
            menor_soma.push_back(sum);
            if (sum == 2) break;
            sum = 1;
            ok = false;
        }
    }

    sort(menor_soma.begin(), menor_soma.end());
    if (menor_soma.size() > 0) cout << menor_soma[0] << "\n";
    else cout << -1 << "\n";
}
