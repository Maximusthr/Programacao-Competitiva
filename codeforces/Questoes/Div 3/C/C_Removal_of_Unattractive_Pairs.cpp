#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    sort(s.begin(), s.end());

    int maior = 1, aux = 1;
    for (int i = 1; i < n; i++){
        if (s[i] == s[i-1]){
            aux++;
        }
        else {
            maior = max(maior, aux);
            aux = 1;
        }
    }

    maior = max(maior, aux);

    int aux2 = n;
    n -= maior;

    cout << max(maior - n, (aux2 % 2 ? 1 : 0)) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}