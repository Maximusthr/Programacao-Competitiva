#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = s.size();

    if (n <= 1){
        cout << -1 << "\n";
        return;
    }

    if (n == 2){
        if (s[0] == s[1]){
            cout << s << "\n";
        }
        else cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n-2; i++){
        if (s[i] == s[i+1]){
            cout << s.substr(i, 2) << "\n";
            return;
        }
        if (s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2]){
            cout << s.substr(i, 3) << "\n";
            return;
        }
    }

    if (s[s.size()-2] == s[s.size()-1]){
        cout << s.substr(s.size()-2, 2) << "\n";
        return;
    }

    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}