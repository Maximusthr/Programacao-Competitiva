#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y; cin >> x >> y;

    string s; cin >> s;
    
    int U = 0, D = 0, R = 0, L = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'U') U++;
        if (s[i] == 'D') D--;
        if (s[i] == 'R') R++;
        if (s[i] == 'L') L--;
    }

    if (x >= 0 && y >= 0 && R >= x && U >= y) cout << "YES" << "\n";
    else if (x >= 0 && y <= 0 && R >= x && D <= y) cout << "YES" << "\n";
    else if (x <= 0 && y >= 0 && L <= x && U >= y) cout << "YES" << "\n";
    else if (x <= 0 && y <= 0 && L <= x && D <= y) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}