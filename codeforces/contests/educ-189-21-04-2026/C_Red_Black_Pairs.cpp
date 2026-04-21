#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<char>> s(2, vector<char> (n));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }

    int par = 0;
    for (int i = 0; i < n; i++){
        if (s[0][i] == s[1][i] && s[0][i] != '*'){
            s[0][i] = '*';
            s[1][i] = '*';
            par++;
        }
        if (i > 0){
            if (s[0][i] == s[0][i-1] && s[0][i] != '*'){
                s[0][i] = '*';
                s[0][i-1] = '*';
                par++;
            }
            if (s[1][i] == s[1][i-1] && s[1][i] != '*'){
                s[1][i] = '*';
                s[1][i-1] = '*';
                par++;
            }
        }
    }

    cout << n - par << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}