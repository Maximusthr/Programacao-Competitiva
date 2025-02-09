#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m; cin >> n >> m;

    vector<int> vetor(n);

    for (auto &i : vetor)
        cin >> i;

    vector<int> seq;
    bool ok = true;

    int aux = 0;
    int temp = 0;
    for (int i = 0; i < n; i++){
        aux = min(vetor[i], abs(vetor[i]-m));
        if (temp <= aux) {
            temp = aux;
            seq.push_back(temp);
        } else if (temp > aux){
            aux = max(vetor[i], abs(vetor[i]-m));
            if (temp > aux){
                ok = false;
                break;
            } else {
                temp = aux;
                seq.push_back(temp);
            }
        }
    }

    long long soma = 0;
    for (int i = 0; i < (int)seq.size(); i++)
        soma += seq[i];

    if (ok) cout << soma << "\n";
    if (!ok) cout << "-1" << "\n";

}
