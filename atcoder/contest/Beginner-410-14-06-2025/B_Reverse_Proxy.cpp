// WA

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> arr(m);
    for (auto &i : arr) cin >> i;

    vector<int> qtd(n+1);
    for (int i = 0; i < m; i++){
        if (arr[i] > 0) qtd[arr[i]]++;
    }

    for (int i = 0; i < m; i++){
        if (arr[i] == 0) {
            int menor = INF;
            int pos = -1;
            for (int j = 1; j <= n; j++){
                if (qtd[j] < menor){
                    menor = qtd[j];
                    pos = j;
               }
            }
            qtd[pos]++;
            arr[i] = pos;
        }
    }

    for (int i = 0; i < m; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}