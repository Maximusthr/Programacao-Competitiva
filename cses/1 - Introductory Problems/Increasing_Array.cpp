#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<long long> num(qtd);
    for (long long &i : num) cin >> i;

    long long ans = 0;
    for (int i = 1; i < qtd; i++){
        if (num[i] < num[i-1]){
            long long aux = num[i-1] - num[i];
            ans += aux;
            num[i] += aux;
        }
    }

    cout << ans << "\n";
}
