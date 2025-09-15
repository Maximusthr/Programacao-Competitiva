#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    vector<bool> vis(n+1);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] == 0) continue;
        vis[arr[i]] = true;
    }

    vector<int> nao_ap;
    for (int i = 1; i <= n; i++){
        if (!vis[i]) nao_ap.push_back(i);
    }

    if (nao_ap.empty()){
        cout << 0 << "\n";
        return;
    }

    reverse(nao_ap.begin(), nao_ap.end());
    
    int cont = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0){
            arr[i] = nao_ap[cont++];
        }
    }

    if (is_sorted(arr.begin(), arr.end())){
        cout << 0 << "\n";
        return;
    }

    int pos_ini = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] != i+1){
            pos_ini = i+1;
            break;
        }
    }
    int pos_fim = 0;
    for (int i = n-1; i >= 0; i--){
        if (arr[i] != i+1){
            pos_fim = i+1;
            break;
        }
    }

    cout << pos_fim - pos_ini + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}