#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    if (s == "abc") cout << "YES" << "\n";
    else if (s[0] == 'a' && s[1] == 'c' && s[2] == 'b') cout << "YES" << "\n";
    else if (s[0] == 'b' && s[1] == 'a'){
        cout << "YES" << "\n";
    }
    else if (s[0] == 'c' && s[2] == 'a') cout << "YES" << "\n";
    else cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}