#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int dif = -1;
    for (int i = 0; i < n; i++){
        if (b[i] != -1){
            dif = a[i] + b[i];
            break;
        }
    }

    for (int i = 0; i < n; i++){
        if (dif != -1 && a[i] > dif){
            cout << 0 << "\n";
            return;
        }
        if (b[i] != -1 && a[i] + b[i] != dif){
            cout << 0 << "\n";
            return;
        }
    }

    for (int i = 0; i < n; i++){
        int v = dif - a[i];
        if (v > k){
            cout << 0 << "\n";
            return;
        }
    }
    if (dif != -1){
        cout << 1 << "\n";
    }
    else {
        // todos são -1
        int maior = *max_element(a.begin(), a.end());
        int menor = *min_element(a.begin(), a.end());

        int v = maior-menor;
        cout << k - v + 1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}