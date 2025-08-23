#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<int> v;

ll memo[1005][8005][4];

ll dp(int i, int valor, int numero){

    if (numero == 0) return (valor == 0);

    if (i == n || valor < 0) return 0;

    if (memo[i][valor][numero] != -1) return memo[i][valor][numero];

    if (valor - v[i] < 0) return memo[i][valor][numero] = dp(i+1, valor, numero);

    ll ans = dp(i+1, valor, numero) + dp(i+1, valor-v[i], numero-1);

    // ans += dp(i+1, valor - v[i], numero - 1);

    return memo[i][valor][numero] = ans;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        v[i] += 1000;
    }

    memset(memo, -1, sizeof(memo));

    int q; cin >> q;
    while(q--){
        int x; cin >> x;

        x += 4000;

        cout << dp(0, x, 4) << "\n";
    }
}