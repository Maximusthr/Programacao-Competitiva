#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    if (s.size() < 3) {
        cout << "NO" << "\n";
        return;
    }

    if ((s[0] != '1' || s[1] != '0') || s[2] == '0' || (s[2] - '0' <= 1 && s.size() == 3)){
        cout << "NO" << "\n";
        return;
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