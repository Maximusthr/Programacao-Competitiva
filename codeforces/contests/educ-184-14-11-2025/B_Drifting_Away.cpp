#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = (int)s.size();

    if (n == 1){
        cout << 1 << "\n";
        return;
    }

    for (int i = 1; i < n-1; i++){
        if (s[i] == '*'){
            if (s[i-1] == '*' || s[i+1] == '*') {
                cout << -1 << "\n";
                return;
            }
        }
    }

    for (int i = 0; i < n-1; i++){
        if ((s[i] == '>' && s[i+1] == '<') || (s[i] == '>' && s[i+1] == '*')){
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = 1; i < n; i++){
        if ((s[i] == '<' && s[i-1] == '>') || (s[i] == '<' && s[i-1] == '*')){
            cout << -1 << "\n";
            return;
        }
    }

    if (n == 2){
        if (s[0] == s[1] && s[0] != '*'){
            cout << 2 << "\n";
            return;
        }
        if ((s[0] == '*' && s[1] == '>') || (s[0] == '<' && s[1] == '*')){
            cout << 2 << "\n";
            return;
        }
        if ((s[0] == '*' && s[1] == '<') || (s[0] == '>' && s[1] == '*') || (s[0] == '*' && s[1] == '*')){
            cout << -1 << "\n";
            return;
        }
    }

    int ans = 1, aux = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '*') {
            aux++;
            ans = max(aux, ans);
            aux = 1;
            continue;
        }

        if (i == n-1 && s[i] == s[i-1]){
            aux++;
            ans = max(aux, ans);
            break;
        }
        
        if (i + 1 < n && (s[i] == s[i+1]) || (s[i+1] == '*') ){
            aux++;
            ans = max(aux, ans);
        }
        else {
            if (i - 1 >= 0 && s[i] == s[i-1]) {
                aux++;
                ans = max(aux, ans);
            }
            aux = 0;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}