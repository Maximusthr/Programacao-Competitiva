#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        set<int> v;
        v.insert(arr[0]);
        
        int contador = 0;
        int tamanho = 1;
        int ans = 1;
        vector<bool> todos(MAX);
        for (int i = 1; i < n; i++){
            if (v.count(arr[i]) == 1 && !todos[arr[i]]){
                todos[arr[i]] = true;
                contador++;
            }
            if (v.count(arr[i]) == 0){
                v.insert(arr[i]);
                contador++;
                tamanho = v.size();
                todos[arr[i]] = true;
            }
            if (contador == tamanho){
                ans++;
                contador = 0;
                todos.assign(MAX, 0);
            }
        }

        cout << ans << "\n";
    }
}