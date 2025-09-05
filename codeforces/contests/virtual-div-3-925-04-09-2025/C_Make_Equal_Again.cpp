#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    bool ok = true;
    for (int i = 1; i < n; i++){
        if (arr[i] != arr[i-1]){
            ok = false;
            break;
        }
    }

    if (ok){
        cout << 0 << "\n";
        return;
    }

    int inicio = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] != arr[i-1]){
            inicio = i;
            break;
        }
    }

    int final = 0;
    for (int i = n-2; i >= 0; i--){
        if (arr[i] != arr[i+1]){
            final = i;
            break;
        }
    }

    int verif = INF;
    if (arr[inicio-1] == arr[final+1]){
        verif = final-inicio+1;
    }

    cout << min({n - inicio, final+1, verif}) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}