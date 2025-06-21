#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;



void solve(){
    vector<string> s(3);
    for (auto &i : s) cin >> i;

    // linhas
    for (int i = 0; i < 3; i++){
        char temp = s[i][0];
        bool ok = true;
        for (int j = 0; j < 3; j++){
            if (temp != s[i][j] || temp == '.') {
                ok = false;
            }
        }
        if (ok){
            cout << temp << "\n";
            return;
        }
    }

    // colunas
    for (int i = 0; i < 3; i++){
        char temp = s[0][i];
        bool ok = true;
        for (int j = 0; j < 3; j++){
            if (temp != s[j][i] || temp == '.'){
                ok = false;
            }
        }
        if (ok){
            cout << temp << "\n";
            return;
        }
    }

    // diag principal
    if (s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[0][0] != '.') {
        cout << s[0][0] << "\n";
        return;
    }
    // diag secundaria
    if (s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[0][2] != '.') {
        cout << s[0][2] << "\n";
        return;
    }

    cout << "DRAW" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}