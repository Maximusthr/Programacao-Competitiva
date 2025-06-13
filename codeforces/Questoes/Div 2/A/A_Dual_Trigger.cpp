#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    int qtd = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1') qtd++;
    }

    if (qtd == 2){
        for (int i = 0; i < n-1; i++){
            if (s[i] == '1' && s[i+1] == '1') {
                cout << "NO" << "\n";
                return;
            }
        }
    }

    cout << (qtd%2 ? "NO" : "YES") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}