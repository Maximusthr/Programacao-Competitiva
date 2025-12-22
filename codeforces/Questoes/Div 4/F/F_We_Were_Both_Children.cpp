#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a;
    vector<int> arr(n+5);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x <= n) {
            a.push_back(x);
            arr[x]++;
        }
    }

    int maior = 0;
    for (int i = 1; i <= n; i++){
        set<int> fatores;
        for (int j = 2; j * j <= i; j++){
            if (i % j == 0){
                fatores.insert(j);
                fatores.insert(i/j);
            }
        }
        fatores.insert(1);
        fatores.insert(i);

        int qtd = 0;

        for (auto it : fatores){
            qtd += arr[it];
        }

        maior = max(maior, qtd);
    }

    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }
}