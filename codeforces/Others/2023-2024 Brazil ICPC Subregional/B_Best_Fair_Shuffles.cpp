// Upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    vector<int> pos(n+1);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        pos[arr[i]] = i+1;
    }

    int qtd = 0;
    int i = 1;
    while (i <= n){
        qtd++;
        while(i + 1 <= n && pos[i+1] > pos[i]){
            i++;
        }
        i++;
    }

    int pot = 0;
    while ((1 << pot) < qtd){
        pot++;
    }
    cout << pot << "\n";
}