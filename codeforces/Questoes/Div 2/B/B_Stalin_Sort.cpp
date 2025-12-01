#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int menor = INF;
    for (int i = 0; i < n; i++){
        int qtd = 0;
        for (int j = i + 1; j < n; j++){
            if (arr[j] > arr[i]) qtd++;
        }

        menor = min(qtd + i, menor);
    }

    cout << menor << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}