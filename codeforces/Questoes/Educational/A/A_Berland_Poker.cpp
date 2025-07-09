#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    if (m == 0){
        cout << 0 << "\n";
        return;
    }

    int qtd = (n/k);

    int maximo = min(qtd, m);

    if (maximo >= m){
        cout << m << "\n";
        return;
    }
    else {
        m -= maximo;

        vector<int> arr(k-1);
        int i = 0;
        while(m > 0){
            arr[i]++;
            i++;
            i %= (k-1);
            m--;
        }
        int maior = 0;
        for (int i = 0; i < k-1; i++){
            maior = max(maior, arr[i]);
        }

        cout << maximo - maior << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}