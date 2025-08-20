#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


void solve(){
    int n; cin >> n;
    
    vector<int> arr(n);
    vector<bool> vis(2e5 + 5);

    map<int, int> qtd;

    int dif = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];

        qtd[arr[i]]++;
        if (!vis[arr[i]]) {
            vis[arr[i]] = 1;
            dif++;
        }
    }

    int maior = 0;
    for (auto [x, y] : qtd){
        maior = max(maior, y);
    }

    if (dif > maior){
        cout << maior << "\n";
    }
    else {
        cout << (dif == maior ? dif - 1 : dif) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}