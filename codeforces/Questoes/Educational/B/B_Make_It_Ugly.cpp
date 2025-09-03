#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int dist = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] != arr[i-1]) dist++;
    }

    if (!dist){
        cout << -1 << "\n";
        return;
    }

    int ini = 0;
    for (int i = 0; i < n-1; i++){
        if (arr[i] != arr[i+1]) {
            ini++;
            break;
        }
        ini++;
    }

    int fim = 0;
    for (int i = n-1; i >= 1; i--){
        if (arr[i] != arr[i-1]) {
            fim++;
            break;
        }
        fim++;
    }

    int meio = INF;
    int aux = 1;
    bool ok = false;
    for (int i = 1; i < n-1; i++){
        if (!ok && arr[i] != arr[i-1]){
            ok = true;
        }
        else if (ok){
            if (arr[i] == arr[i+1]){
                aux++;
            }
            else {
                meio = min(meio, aux);
                aux = 1;
                ok = false;
            }
        }
    }

    cout << min({meio, ini, fim}) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}