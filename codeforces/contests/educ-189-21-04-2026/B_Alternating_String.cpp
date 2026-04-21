#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    int n = s.size();

    int a = 0, b = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'a') a++;
        else b++;
    }

    if (abs(a-b) >= 4) {
        cout << "NO" << "\n";
        return;
    }

    for (int i = 0; i < n-3; i++){
        string aux = s.substr(i, 4);
        if (aux == "aaaa" || aux == "bbbb"){
            cout << "NO" << "\n";
            return;
        }
    }

    bool flag = false;
    bool foi = false;
    for (int i = 1; i < n; i++){
        if (!flag && s[i] == s[i-1]) {
            flag = true;
            if (foi){
                cout << "NO" << "\n";
                return;
            }
            continue;
        }

        if (flag && s[i] == s[i-1]){
            foi = true;
            flag = false;
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}