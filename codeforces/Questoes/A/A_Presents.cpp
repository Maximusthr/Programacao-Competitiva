#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    vector<int> vet(t);
    for (auto &i: vet) cin >> i;

    int new_vet[t];

    for (int i = 0; i < t; i++)
        new_vet[vet[i]-1] = i;
    
    for (int i = 0; i < t; i++ )
        cout << new_vet[i] + 1 << " ";
    
    cout << "\n";
}