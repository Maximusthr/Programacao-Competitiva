#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    int ans = 0;
    bool ok = false;
    for (int i = 0; i < n; i++){
        if (ok){
            ok = false;
            continue;
        }
        if (s[i] == '@') ans++;
        
        if (i < n-2 && s[i+1] == '*' && s[i+2] == '*'){
            cout << ans << "\n";
            return;
        }

        if (s[i+1] == '*'){
            ok = true;
            continue;
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